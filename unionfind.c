int ancetre (int x, int *pere)
{
    return (pere[x]==-1) ? x : (ancetre(pere[x],pere)) ;
}

void makeset (int x, int *pere)
{
    pere[x] = -1 ;
}

void Union (int x, int y, int *pere)
{
    int a_x = ancetre(x,pere), a_y = ancetre(y,pere) ;
    if (a_x != a_y)
        pere[a_x] = a_y ;
}
