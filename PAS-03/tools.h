int clampInt(int pValue, int pMin, int pMax){
    int temp = pValue < pMin ? pMin : pValue;
    return pMax == -1 ? temp : temp > pMax ? pMax : temp;
}

