vector<int> plusOne(vector<int> &digits)
{
    int x = digits.size() - 1;

    for (int i = x; i >= 0; --i)
    { /* start with the final digit and make it 0 if it was orignally 9, as 9+1 = 10. We'll keep track of all 9s in each iteration as there can be more nines in that number*/
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        { // this digit is not 9 so there is no case of carry here, we can increment it by 1
            digits[i] += 1;
            return digits; //there was no case of 9, hence you can return the number safely.
        }
    }
    /* 
    if program hasn't yet returned which means there was a 9, and we've already converted 9 to 0 so we need to add 1 of the carry in the first digit */
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}