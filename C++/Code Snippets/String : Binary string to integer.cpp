int toInt(std::string binstr)
{
    int result = 0;
    int power = 0;

    for(int i=binstr.size()-1; i >= 0; i--)
    {
        result += pow(2,power) * (binstr[i] - '0');
        power++;
    }


    return result;
}
