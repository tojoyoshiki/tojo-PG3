#include <stdio.h>

//Ä‹A“I‚È’À‹à
double Recursive(int hours) {
    double wage = 100.0; //Å‰‚Ì‹‹‚Í100‰~
    double total = wage;

    for (int i = 1; i < hours; i++) {
        wage = wage * 2 - 50; //Ÿ‚Ì‹‹‚ğŒvZ
        total += wage; //‘’À‹à‚É‰ÁZ
    }

    return total;
}

//ˆê”Ê“I‚È’À‹à
double Standard(int hours) {
    const double hourlyWage = 1072.0; // ‹‹1072‰~
    return hourlyWage * hours;
}

int main() {
    int hours;

    //˜J“­ŠÔ‚ğ“ü—Í‚µ‚Ä‚à‚ç‚¤
    printf("“­‚¢‚½ŠÔ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ");
    scanf_s("%d", &hours);

    //Še’À‹à‘ÌŒn‚ÉŠî‚Ã‚¢‚ÄŒvZ
    double recursiveTotal = Recursive(hours);
    double standardTotal = Standard(hours);

    // Œ‹‰Ê‚ğ•\¦
    printf("Ä‹A“I‚È’À‹à‘ÌŒn‚Å‚Ì‘’À‹à: %.2f‰~\n", recursiveTotal);
    printf("ˆê”Ê“I‚È’À‹à‘ÌŒn‚Å‚Ì‘’À‹à: %.2f‰~\n", standardTotal);

    //”äŠr
    if (recursiveTotal > standardTotal) {
        printf("Ä‹A“I‚È’À‹à‘ÌŒn‚Ì•û‚ª‚‚¢\n");
    }
    else if (recursiveTotal < standardTotal) {
        printf("ˆê”Ê“I‚È’À‹à‘ÌŒn‚Ì•û‚ª‚‚¢\n");
    }
    else {
        printf("‚Ç‚¿‚ç‚Ì’À‹à‘ÌŒn‚Å‚à“¯‚¶\n");
    }

    return 0;
}
