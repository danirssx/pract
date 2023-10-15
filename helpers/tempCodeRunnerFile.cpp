int main() {
    int var1 = 20;
    int* pX = &var1;

    mem::MemView(pX, 2, 4);

    return 0;
}