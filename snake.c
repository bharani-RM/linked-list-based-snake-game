#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct Node {
    int x, y;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;
int foodX, foodY;
int score = 0;
char dir = 'd';
int speed = 150;
time_t lastSpeedChange;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x; newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void addHead(int x, int y) {
    Node* newNode = createNode(x, y);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) tail = newNode;
}

void removeTail() {
    if (head == NULL || head->next == NULL) return;
    Node* temp = head;
    while (temp->next != tail) temp = temp->next;
    free(tail);
    tail = temp;
    tail->next = NULL;
}

int isOnSnake(int x, int y) {
    Node *t = head;
    while (t) {
        if (t->x == x && t->y == y) return 1;
        t = t->next;
    }
    return 0;
}

void generateFood() {
   
    do {
        foodX = rand() % (WIDTH - 2) + 1;
        foodY = rand() % (HEIGHT - 2) + 1;
    } while (isOnSnake(foodX, foodY));
}

int checkCollision() {
    Node* temp = head->next;
    while (temp) {
        if (head->x == temp->x && head->y == temp->y) return 1;
        temp = temp->next;
    }
   
    if (head->x <= 0 || head->x >= WIDTH-1 || head->y <= 0 || head->y >= HEIGHT-1) return 1;
    return 0;
}

void drawBoard() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == HEIGHT - 1 || x == WIDTH - 1 || y == 0 || x == 0) printf("H");
            else if (x == head->x && y == head->y) printf("O");
            else if (x == foodX && y == foodY) printf("F");
            else {
                int body = 0;
                Node* temp = head->next;
                while (temp) {
                    if (temp->x == x && temp->y == y) { printf("o"); body = 1; break; }
                    temp = temp->next;
                }
                if (!body) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score: %d   Speed: %d ms\n", score, speed);
    printf("Controls: w (up), s (down), a (left), d (right)\n");
}

void moveSnake() {
    int newX = head->x, newY = head->y;
    if (dir == 'w') newY--;
    else if (dir == 's') newY++;
    else if (dir == 'a') newX--;
    else if (dir == 'd') newX++;
    addHead(newX, newY);
    if (head->x == foodX && head->y == foodY) {
        score += 10;
        generateFood();
    } else removeTail();
}

void freeSnake() {
    Node *t = head;
    while (t) {
        Node *n = t->next;
        free(t);
        t = n;
    }
    head = tail = NULL;
}

void initGame() {
    freeSnake();
    score = 0;
    dir = 'd';
    speed = 150;
    lastSpeedChange = time(0);
   
    addHead(WIDTH / 2, HEIGHT / 2);
    addHead(WIDTH / 2 - 1, HEIGHT / 2);
    generateFood();
}

int playOneRound(int playerNumber) {
    initGame();
   
    system("cls");
    printf("Player %d - Press any key to start (use w/a/s/d). Good luck!\n", playerNumber);
    getch();
    system("cls");

    while (1) {
        if (kbhit()) {
            char c = getch();
           
            if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            if ((c == 'w' && dir != 's') || (c == 's' && dir != 'w') || (c == 'a' && dir != 'd') || (c == 'd' && dir != 'a')) dir = c;
        }

        moveSnake();
        if (checkCollision()) {
            system("cls");
            printf("\n=== GAME OVER (Player %d) ===\nFinal Score: %d\n", playerNumber, score);
           
            Sleep(1500);
            break;
        }
        drawBoard();

        if (difftime(time(0), lastSpeedChange) >= 10) {
            speed = 80 + rand() % 200;
            lastSpeedChange = time(0);
        }
        Sleep(speed);
    }

    int finalScore = score;
    freeSnake();
    return finalScore;
}

int main() {
    srand((unsigned int)time(0));
    int mode = 0;
    printf("----------------------------------------------------------\n");
    printf("                WELCOME TO SNAKE GAME           \n");
    printf("----------------------------------------------------------\n");
    printf("Choose mode:\n1 = One player mode\n2 = Two players mode\n");
    if (scanf("%d", &mode) != 1) {
        printf("Invalid input.\n");
        return 0;
    }
   
    while (getchar() != '\n');

    if (mode == 1) {
        int s = playOneRound(1);
        printf("\nThanks for playing! Your score: %d\n", s);
    } else if (mode == 2) {
        int scores[2] = {0,0};
        for (int i = 0; i < 2; i++) {
            scores[i] = playOneRound(i + 1);
           
            if (i == 0) {
                printf("\nPlayer 1 finished with %d points. Press any key when Player 2 is ready...\n", scores[0]);
                getch();
            }
        }
        printf("\n--- Results ---\nPlayer 1: %d\nPlayer 2: %d\n", scores[0], scores[1]);
        if (scores[0] > scores[1]) printf("Winner: Player 1!\n");
        else if (scores[1] > scores[0]) printf("Winner: Player 2!\n");
        else printf("It's a tie!\n");
    } else {
        printf("Invalid mode selected.\n");
    }

    return 0;
} 
