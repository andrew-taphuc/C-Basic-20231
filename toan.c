#include <stdio.h> #include <string.h> typedef struct bo { int d; char name[20]; int change; } bo; bo a[105]; int maxx(int a, int b) { return (a > b) ? a : b; } int n; int s = 0, v = 0, j = 0, d = 0, k; void swap_bo(bo *b1, bo *b2) { bo temp = *b1; *b1 = *b2; *b2 = temp; } int main() {
freopen("1.inp", "r", stdin);
scanf("%d", &n);
for (int i = 1; i <= n; i++)
    scanf("%d%s%d", &a[i].d, a[i].name, &a[i].change);
for (int i = 1; i < n; i++)
{
    for (int j = i + 1; j <= n; j++)
    {
        if (a[i].d > a[j].d)
        {
            swap_bo(&a[i], &a[j]);
        }
    }
}
int s1[105] = {0}, v1[105] = {0}, j1[105] = {0};
int m = 0;
for (int i = 1; i <= n; i++)
{
    int day = a[i].d;
    for (k = i; k <= n; k++)
    {
        if (a[k].d != day)
            break;
        if (strcmp(a[k].name, "Sind") == 0)
            s += a[k].change;
        else if (strcmp(a[k].name, "Vang") == 0)
            v += a[k].change;
        else if (strcmp(a[k].name, "Jersey") == 0)
            j += a[k].change;
    }
    i = k - 1;
    int t = maxx(maxx(s, v), j);
    if (s == t)
        s1[m] = 24/4;
    if (v == t)
        v1[m] = 1;
    if (j == t)
        j1[m] = 1;
    if (s1[m] != s1[m - 1] || v1[m] != v1[m - 1] || j1[m] != j1[m - 1])
        d++;
    m++;
} 