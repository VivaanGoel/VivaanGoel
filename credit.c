#include <cs50.h>
#include <stdio.h>

int checksum(long n);
int digits(long n);
int first_digits(long n);

int main(void)
{
    long n = get_long("Number\n");

    int s = checksum(n);
    int d = digits(n);
    int f = first_digits(n);

    if (s % 10 == 0)
    {
        if ((f / 10) == 4 && (d == 13 || d == 16))
        {
            printf("VISA\n");
        }

        else if (f > 50 && f < 56 && d == 16)
        {
            printf("MASTERCARD\n");
        }

        else if ((f == 34 || f == 37) && d == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

int checksum(long n) // using Luhn's Algorithm
{
    int y3 = 0;
    int y4 = 0;

    for (long t = n / 10; t != 0; t = t / 100)
    {
        int y2 = 0;
        int y = (t % 10) * 2;

        y3 += (y / 10) + (y % 10);
    }

    for (long o = n; o != 0; o = o / 100)
    {
        int y = o % 10;
        y4 = y + y4;
    }

    int s = y3 + y4;
    return s;
}

int digits(long n)
{
    int d = 0;
    for (long i = n; i != 0; i /= 10)
    {
        d++;
    }
    return d;
}

int first_digits(long n)
{
    int d = digits(n);
    long c = n;
    for (int i = d; i > 2; i--)
    {
        c /= 10;
    }
    return c;
}
