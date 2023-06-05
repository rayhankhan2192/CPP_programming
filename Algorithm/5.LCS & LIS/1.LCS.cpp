#include <bits/stdc++.h>
using namespace std;

int LCS(char* X, char* Y, int lengthX, int lengthY, char* lcsString){
   int L[lengthX + 1][lengthY + 1];
   int i, j;

    // Building the L[m+1][n+1] table in bottom-up manner
    for (i = 0; i <= lengthX; i++) {
        for (j = 0; j <= lengthY; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
                
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Constructing the LCS string
    int index = L[lengthX][lengthY];
    lcsString[index] = '\0'; // Setting the null terminator

    i = lengthX;
    j = lengthY;
    while (i > 0 && j > 0){
        if (X[i - 1] == Y[j - 1]){
            lcsString[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    return L[lengthX][lengthY];
}
int main(){
    char X[] = "TUMMUNICH";
    char Y[] = "MUNICH";
    int lengthX = strlen(X);
    int lengthY = strlen(Y);

    char lcsString[lengthX + lengthY];
    int lcsLength = LCS(X, Y, lengthX, lengthY, lcsString);

    printf("Length of LCS: %d\n", lcsLength);
    printf("LCS: %s\n", lcsString);
}