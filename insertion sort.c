#include <stdio.h>
int main()
{
int n, array[20], i, j, temp;
printf("Enter the Number of Element : ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
printf("Enter the Element into array : ");
scanf("%d", &array[i]);
}
for (i = 1; i < n; i++)
{
j = i;
while (j > 0 && array[j] < array[j - 1])
{
temp = array[j];
array[j] = array[j - 1];
array[j - 1] = temp;
j--;
}
}
for (i = 0; i < n; i++)
{
printf("%d\t", array[i]);
}
system("PAUSE");
return 0;
}



Output :
Enter the Number of Element : 5
Enter the Element into array : 6
Enter the Element into array : 2
Enter the Element into array : 8
Enter the Element into array : 1
Enter the Element into array : 0
0 1 2 6 8