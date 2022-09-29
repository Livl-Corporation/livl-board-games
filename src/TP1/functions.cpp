int somme(int nombre1, int nombre2)
{
    return nombre1 + nombre2;
}

void inverser(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void replaceBySum(int &a, int &b, int &result)
{
    result = a + b;
}

void replaceBySum(int *a, int *b, int *result)
{
    *result = *a + *b;
}