int lengthOfLastWord(char * s){
    int i = 0, counter = 0;
    short palavra_acabou = 0;
    while  (s[i] != '\0') {
        if (s[i] != ' ') {
            counter += 1;
        } else if (s[i] == ' ') {
            palavra_acabou = 1;
        }
        if (palavra_acabou && s[i] != ' ') {
            palavra_acabou = 0;
            counter = 1;
        }
        i++;
    }
    return counter;
}