 #include <stdio.h>
 #include <stdlib.h>

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

 int main()
 {
    int n, *tree, *distance, g, rslt = 0;

    scanf("%d", &n);
    tree = (int *)calloc(n, sizeof(int));
    distance = (int *)calloc(n - 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
        //printf("tree[%d] = %d\n", i, tree[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        distance[i] = tree[i + 1] - tree[i];
        //printf("distance[%d] = %d\n", i, distance[i]);
    }
    //printf("\n\n");
    g = gcd(distance[0], distance[1]);
    //printf("g = %d\n\n", g);
    //printf("---------cal gcd--------\n\n");
    for (int i = 1; i < n - 2; i++)
    {
        //printf("g = %d distance[%d + 1] = %d\n", g, i, distance[i + 1]);
        g = gcd(g, distance[i + 1]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        rslt += distance[i] / g - 1;
        //printf("i = %d rslt = %d\n", i, rslt);
    }
    printf("%d", rslt);

    free(tree);
    free(distance);
    return 0;
 }