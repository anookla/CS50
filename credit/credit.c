#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

int isLengthMatching(long card_number);
void checkStartingDigits(long card_number, int totalDigits);
bool checkSum(long cardNumber, int totalDigits);

int totalDigits = 0;
int twoDigits = 0;
int firstDigit = 0;

int main()
{
    long card_Number;
    int Length;
    card_Number = get_long("Please enter the credit card number: ");

    Length = isLengthMatching(card_Number);
    bool isValidCheckSum = checkSum(card_Number, totalDigits);

    if (isValidCheckSum)
    {
        checkStartingDigits(card_Number, totalDigits);

        if ((Length == 13 || Length == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }

        else if (Length == 15 && (twoDigits == 34 || twoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if ((Length == 16) && (twoDigits == 51 || twoDigits == 52 || twoDigits == 53 ||
                                    twoDigits == 54 || twoDigits == 55))
        {
            printf("MASTERCARD\n");
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

// find length of card

int isLengthMatching(long card_number)
{

    do
    {
        card_number = (card_number / 10);
        totalDigits++;
    }
    while (card_number != 0);

    return totalDigits;
}

// get the first two digits

void checkStartingDigits(long card_number, int total)
{

    while (total != 1)
    {
        if (total == 2)
        {
            twoDigits = card_number;
        }
        card_number = card_number / 10;
        total--;
    }
    firstDigit = card_number;
}

// validate checksum
bool checkSum(long cardNumber, int totalLength)
{

    int sum = 0;

    int counter = totalLength;

    long number = cardNumber;

    while (counter > 0)
    {
        int lastTwoDigits = number % 100;
        int lastDigit = lastTwoDigits % 10;
        int lastSecondDigit = lastTwoDigits / 10;

        number = number / 100;
        counter = counter - 2;
        if ((lastSecondDigit * 2) / 10 != 0)
        {
            sum = sum + ((lastSecondDigit * 2)) % 10 + ((lastSecondDigit * 2) / 10);
        }
        else
        {
            sum = sum + (lastSecondDigit * 2);
        }
    }

    while (totalLength > 0)
    {
        int lastTwoDigitsNew = cardNumber % 100;
        int lastDigitNew = lastTwoDigitsNew % 10;

        cardNumber = cardNumber / 100;
        totalLength = totalLength - 2;
        sum = sum + lastDigitNew;
    }

    if (sum % 10 == 0)
    {
        return true;
    }

    return false;
}
