#include <iostream>
#include <cctype>
#include <cmath>
//declarations
char *encode( char *plaintext, unsigned long key );
char *decode( char *ciphertext, unsigned long key );
bool is_valid_ciphertext(char *str);
bool is_valid_plaintext(char *str);


//definitions
bool is_valid_ciphertext(char *str){
    for (int i = 0; true; i++) {
        if (str[i]=='\0') {
            if (i%5==0) return true;
        }
        if (str[i]<33||str[i]>117) return false;
    }
}

bool is_valid_plaintext(char *str){
    for (int i = 0; true; i++) {
        if (str[i]!='\0') return std::isprint(str[i]) || std::isspace(str[i]);
    }
}

char *decode(char *ciphertext, unsigned long key){

    // length of ciphertext
    int length = 0;
    
    for (int m = 0; true; m++) {
        if (ciphertext[m]=='\0') {
            length = m;
            break;
        }
    }
    
    // declare the answer array.
    char answer[4*length/5];
    
    //
    unsigned int res = 0;
    for (int r = 0; r<(length/5); r++) {
        res = (static_cast<unsigned char>(ciphertext[5*r]-33) * pow(85, 4))+(static_cast<unsigned char>(ciphertext[5*r+1]-33) * pow(85, 3))+(static_cast<unsigned char>(ciphertext[5*r+2]-33) * pow(85, 2))+
        (static_cast<unsigned char>(ciphertext[5*r+3]-33) * 85) + static_cast<unsigned char>(ciphertext[5*r+4]-33);
        
        for (int place = 4*r+3; place >= 4*r ; place--) {
            answer[place] = res % 256;
            res /= 256;
        }
    }
    
    unsigned int S[256];
    //initialize the S array. correct.
    for (int i = 0; i<256; i++) {
        S[i] = i;
    }
    
    //turn key into a binary array. correct.
    int keylist[64];
    for (int i = 0; i<64; i++) {
        keylist[i] = (key%2);
        key /= 2;
    }
    //begin randomization correct.
    int i = 0;
    int j = 0;
    for (int time = 0; time < 256; time++) {
        int k = i % 64;
        j = (j + S[i] + keylist[k]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        i = (i+1) % 256;
    }
    
    for (int time = 0; time < 4*length/5; time++) {
        int r = 0;
        i = (i+1) % 256;
        j = (j + S[i]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        r = (S[i] + S[j]) % 256;
        answer[time]^=S[r];
    }
    
    for (int i = 0; i<4*length/5; i++) {
        std::cout << answer[i];
    }
    
    char *ptr = ciphertext;
    return ptr;
}












char *encode(char *plaintext, unsigned long key){
    unsigned int S[256];
    //initialize the S array. correct.
    for (int i = 0; i<256; i++) {
        S[i] = i;
    }
    
    //turn key into a binary array. correct.
    int keylist[64];
    for (int i = 0; i<64; i++) {
        keylist[i] = (key%2);
        key /= 2;
    }
    //begin randomization correct.
    int i = 0;
    int j = 0;
    for (int time = 0; time < 256; time++) {
        int k = i % 64;
        j = (j + S[i] + keylist[k]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        i = (i+1) % 256;
    }
    
    //length of plaintext. correct.
    int length = 0;
    for (int m = 0; true; m++) {
        if (plaintext[m]=='\0') {
            length = m;
            break;
        }
    }
    
    
    char plain[int(std::ceil(length/4.0)*4)]; //prepare the new plaintext array for non-4-multiple.
    int len = 0; //new plaintext array's length.
   
    // turn non-4-multiple to 4-multiple length's array. correct.
    if (length % 4!=0) {
        for (int i = 0; i<length; i++) {
            plain[i] = plaintext[i];
        }
        for (int q = length; q < std::ceil(length/4.0)*4; q++) {
            plain[q] = '\0';
        }
        len = std::ceil(length/4.0)*4;
    }
    
    //begin encryption. correct.
    for (int time = 0; time < length; time++) {
        int r = 0;
        i = (i+1) % 256;
        j = (j + S[i]) % 256;
        int temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        r = (S[i] + S[j]) % 256;
        plaintext[time] ^= S[r];
    }
    //ascii armour.
   
    unsigned int res = 0;
    char ans[5*int(std::ceil(length/4.0))];
    
    if (length%4==0) {
        for (int r = 0; r < (length/4); r++) {
            res = (static_cast<unsigned char>(plaintext[4*r]) * pow(2, 24))+(static_cast<unsigned char>(plaintext[4*r+1]) * pow(2, 16))+(static_cast<unsigned char>(plaintext[4*r+2]) * pow(2, 8))+ static_cast<unsigned char>(plaintext[4*r+3]);
            for (int place = 5*r+4; place>=5*r; place--) {
                ans[place] = (res%85)+33;
                res /= 85;
            }
        }
    }
    else{
        for (int r = 0; r < (len/4); r++) {
            res = (static_cast<unsigned char>(plain[4*r]) * pow(2, 24))+(static_cast<unsigned char>(plain[4*r+1]) * pow(2, 16))+(static_cast<unsigned char>(plain[4*r+2]) * pow(2, 8))+ static_cast<unsigned char>(plain[4*r+3]);
            for (int place = 5*r+4; place>=5*r; place--) {
                ans[place] = (res%85)+33;
                res /= 85;
            }
        }
    }
    
    for (int i = 0; i<5*int(std::ceil(length/4.0)); i++) {
        std::cout << ans[i];
    }
    
    
    char *ptr = ans;
    return ptr;
}










#ifndef MARMOSET_TESTING
int main(){
    char list[] = {"l=]V]&9!>trOu*9"};
    decode(list, 51323);

    return 0;
}
#endif
