extern double __enzyme_fwddiff(void*, double[100], double[100], double[100], double[100]);
void f(double x[100], double out[100]) {
    int prev = 0;
    for(int i = 0; i < 100; i++) {
        out[i] = x[i] - prev/x[i];
        prev = x[i];
    }
}
void jvpf(double x[100], double v[100], double out[100], double dout[100]) {
    __enzyme_fwddiff((void*)f, x, v, out, dout);
}
