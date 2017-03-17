/******************************************************************************/
/* Gozde DOGAN - 131044019
/* CSE312 - Homework1
/* 
/* Kisa odev aciklamasi
/*
/******************************************************************************/



make yapildi.
make icerigi:
    g++ *.cpp -o emu8080
Sonrasinda ise 
    ./emu8080 .com type 
seklinde calistirabilirsin.
Calistirirken make yapabilirsiniz.

Search.asm, Sort.asm, PrintNumbers.asm, PrintNumbersRev.asm, test.asm yazildi.

Search yaparken hexadecimal bir sayi giriniz(eg. 1A gibi)
Program onu kabul ediyor.

PrintNumbers.asm ->
            sayilari 0 dan baslayip 50 ye kadar yaziyor
            PRINT_B kullanildi
PrintNumbersRev.asm ->
            sayilari 100 den baslayip 50 ye kadar yaziyor
            PRINT_B kullanildi
Search.asm ->
            Userdan READ_B ile deger aliyor
            Bu degeri PRINT_B ile ekrana yaziyor
            Girilen degeri array de ariyor
            Buldugu index'i PRINT_B ile ekrana yaziyor
            Sort.asm icinde dw ile tanimlanacak dediginiz 
            icin burada array db ile tanimlandi
Sort.asm ->
           dw ile tanimlanan arrayi siralamaya calisiyor.
           Siralanmis arrayi PRINT_STR ile ekrana yaziyor.
test.asm ->
            Burada yazilan system call lar test edildi.
            READ_B ile klavyeden deger aliyor.
            PRINT_B ile aldigi bu degeri ekrana yaziyor.
            READ_MEM ile klavyeden deger aliyor.
            PRINT_MEM ile aldigi bu degeri ekrana basiyor.
            READ_STR ile klavyeden string aliyor.
            PRINT_STR ile bu stringi ekrana basiyor.        

Odev ile gelen printstr.asm, sum.asm ve sum2.asm icin de .com uzantili dosyalar 
olusturuldu.
