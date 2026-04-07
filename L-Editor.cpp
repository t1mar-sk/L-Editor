#include <iostream>
#include <cstring>
#include <cstdlib>

struct Point {
    int x;
    int y;
};

void println(const char* s) { std::cout << s << std::endl; }
void println(int s) { std::cout << s << std::endl; }
void print(const char* s) { std::cout << s; }
void print(int s) { std::cout << s; }

char* input(const char* prompt) {
    static char buffer[256];
    print(prompt);
    std::cin.getline(buffer, 256);
    return buffer;
}

class ScreenRenderer {
private:
    int x, y;
    int maxW = 50, maxH;

public:
    ScreenRenderer(int h) : x(0), y(0), maxH(h) {}
    void SetNewHeight(int h) { maxH = h; }
    void move(char direction) {
        if (direction == 'l' && x > 0) x--;
        else if (direction == 'r' && x < maxW - 1) x++;
        else if (direction == 'u' && y > 0) y--;
        else if (direction == 'd' && y < maxH - 1) y++;
    }
    int getX() { return x; }
    int getY() { return y; }
};

class TextEditor {
private:
    char text[256];
    int cursor = 0;
    int MaxL = 50;

public:
    const char* ReadBufferText() { return text; }
    void initBuffer() {
        for (int i = 0; i < 256; i++) text[i] = '\0';
        cursor = 0;
    }
    int TextBufferLen() { return cursor; }
    void AddChar(char c) {
        if (cursor < 254) {
            text[cursor] = c;
            cursor++;
            text[cursor] = '\0';
        }
    }
    void DeleteChar() {
        if (cursor > 0) {
            cursor--;
            text[cursor] = '\0';
        }
    }
    void RenderText() {
        for (int i = 1; i <= 5; i++) {
            int pos = (MaxL * i) - 1;
            if (pos < 256 && text[pos-1] != '\0' && text[pos] != '\n' && text[pos] != '\0') {
                text[pos] = '\n';
            }
        }
    }
};

class TextEngine {
private:
    TextEditor MEditor;
    ScreenRenderer MRender;
    bool brakeFlag = false;

    bool isCmd(const char* input, const char* target) {
        return strcmp(input, target) == 0;
    }

    void DrawInterface() {
        system("cls");
        const char* buffer = MEditor.ReadBufferText();
        int curPos = MEditor.TextBufferLen();

        println("--- EDITOR v1.1 ---");
        for (int i = 0; i <= curPos; i++) {
            if (i == curPos) print("|");
            if (buffer[i] != '\0') std::cout << buffer[i];
        }
        println("\n--------------");
        print("Cursor X: "); print(MRender.getX());
        print(" Y: "); println(MRender.getY());
    }

public:
    TextEngine() : MRender(5) { MEditor.initBuffer(); }

    void CheckText(char* inputText) {
        if (isCmd(inputText, ":q") || isCmd(inputText, ":e")) brakeFlag = true;
        else if (isCmd(inputText, ":h")) {
            system("cls");
            println("HELP: :q=Exit, :i=Info, :h=Help, :D=Del, :l/r/u/d=Move");
            input("Press Enter...");
        }
        else if (isCmd(inputText, ":i")) {
            println("V1.1 by Mr.Lobster");
            input("Press Enter...");
        }
        else if (isCmd(inputText, ":l")) MRender.move('l');
        else if (isCmd(inputText, ":r")) MRender.move('r');
        else if (isCmd(inputText, ":u")) MRender.move('u');
        else if (isCmd(inputText, ":d")) MRender.move('d');
        else if (isCmd(inputText, ":D")) {
            MEditor.DeleteChar();
            MRender.move('l');
        }
        else {
            for (int i = 0; inputText[i] != '\0'; i++) {
                MEditor.AddChar(inputText[i]);
                MRender.move('r');
            }
        }
    }

    void run() {
        while (!brakeFlag) {
            DrawInterface();
            char* userInput = input("> ");
            CheckText(userInput);
            MEditor.RenderText();
        }
    }
};

int main() {
    TextEngine engine;
    engine.run();
    return 0;
}