#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 100
#define COLS 100

char labirinto[ROWS][COLS];
int visitado[ROWS][COLS];
int pai[ROWS][COLS][2];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void readGridFromFile(char *matrix, int rows, int cols, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    static char line[1024];
    int r = 0;

    while (fgets(line, sizeof(line), file) && r < rows) {
        int c = 0;
        char *pos = line;
        while (*pos != '\n' && c < cols) {
            *(matrix + r * cols + c) = *pos++;
            c++;
        }
        r++;
    }

    fclose(file);
}

void writeGridToFile(char *matrix, int rows, int cols, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            fputc(*(matrix + r * cols + c), file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

int dentroDoMapa(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

void gerarNovoGrid(float porcentagemObstaculos) {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            labirinto[i][j] = ' ';
        }
    }

    labirinto[0][0] = 'A';
    labirinto[ROWS - 1][COLS - 1] = 'B';

    int totalCelulas = ROWS * COLS;
    int totalObstaculos = (int)(porcentagemObstaculos / 100.0 * totalCelulas);
    int colocados = 0;

    while (colocados < totalObstaculos) {
        int x = rand() % ROWS;
        int y = rand() % COLS;

        if (labirinto[x][y] == ' ') {
            labirinto[x][y] = 'x';
            colocados++;
        }
    }

    writeGridToFile(&labirinto[0][0], ROWS, COLS, "grid.txt");
    printf("Novo grid salvo em grid.txt.\n");
}

int bfs(int sx, int sy) {
    int fila[ROWS * COLS][2];
    int frente = 0, tras = 0;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            visitado[i][j] = 0;
            pai[i][j][0] = -1;
            pai[i][j][1] = -1;
        }

    fila[tras][0] = sx;
    fila[tras][1] = sy;
    tras++;

    visitado[sx][sy] = 1;

    while (frente < tras) {
        int x = fila[frente][0];
        int y = fila[frente][1];
        frente++;

        if (labirinto[x][y] == 'B') {
            printf("Caminho encontrado!\n");

            // Marca caminho
            while (pai[x][y][0] != -1) {
                int px = pai[x][y][0];
                int py = pai[x][y][1];
                if (labirinto[px][py] != 'A') {
                    labirinto[px][py] = 'o';
                }
                x = px;
                y = py;
            }

            // salva o grid com o caminho
            writeGridToFile(&labirinto[0][0], ROWS, COLS, "path.txt");
            printf("Grid resolvido salvo em path.txt.\n");
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (dentroDoMapa(nx, ny) && !visitado[nx][ny] && (labirinto[nx][ny] == ' ' || labirinto[nx][ny] == 'B')) {
                visitado[nx][ny] = 1;
                fila[tras][0] = nx;
                fila[tras][1] = ny;
                tras++;
                pai[nx][ny][0] = x;
                pai[nx][ny][1] = y;
            }
        }
    }

    printf("Não foi possível encontrar o caminho.\n");
    return 0;
}

int main() {
    float porcentagem;

    printf("Bem-vindo ao sistema de navegacao de drones autonomos!\n");
    printf("Informe o nivel percentual de obstaculos (0–100): ");
    scanf("%f", &porcentagem);

    gerarNovoGrid(porcentagem);

    readGridFromFile(&labirinto[0][0], ROWS, COLS, "grid.txt");

    int startX = -1, startY = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (labirinto[i][j] == 'A') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }

    if (startX == -1 || startY == -1) {
        printf("Ponto A não encontrado no grid!\n");
        return 1;
    }

    bfs(startX, startY);

    return 0;
}
