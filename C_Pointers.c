#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// isdigit, isalpha, isalnum
// isupper, islower
// isspace, ispunct
// toupper, tolower

int main(){

    char c1 = 'z'; // ASCII 'z' = 122,
    int c1_int = c1; // -> c1_int = 122;

    // isdigit(): girilen char rakamsa 1 deðilse 0
    char rakam = '3';
    printf("isdigit('3'):%d\n",isdigit(rakam));

    // isalpha(): girilen char harfse 1 deðilse 0
    char harf = 'h';
    printf("isalpha('h'):%d\n",isalpha(harf));

    // isalnum(): girilen char harf veya rakamsa 1 deðilse 0
    printf("isalnum('3'):%d\nisalnum('h'):%d\n\n",isalnum(rakam),isalnum(harf));

    // islower(): girilen char küçük harfse 1 deðilse 0
    printf("islower('h'):%d\nislower('H'):%d\n",islower(harf),islower('H'));

    // isupper(): girilen char büyük harfse 1 deðilse 0
    printf("isupper('h'):%d\nisupper('H'):%d\n\n",isupper(harf),isupper('H'));

    // isspace(): girilen char boþluk, \f, \n, \v, \t, \r ise 1 deðilse 0
    printf("isspace(' '):%d\nisspace('h'):%d\n\n",isspace(' '),isspace(harf));

    // ispunct(): girilen char noktalama iþareti veya sembolse 1 deðilse 0
    printf("ispunct(','):%d\nispunct('&'):%d\nispunct('h'):%d\n\n",ispunct(','), ispunct('&'),ispunct(harf));

    // tolower(): girilen char büyük harfse küçük harfe çevirir
    printf("tolower('H'):%c\n",tolower('H'));

    // toupper(): girilen char küçük harfse büyük harfe çevirir
    printf("toupper('h'):%c\n",toupper(harf));

    return 0;
}

// STRINGLER

/*
Dizileri ve çok boyutlu dizileri gördük. Katar dediðimiz þey de aslýnda bir dizidir.
 
Deðiþken tipi char yani karakter olan diziler, 'katar' ya da ingilizce adýyla 'string' olarak isimlendirilirler.

Katarlarý, þimdiye kadar gördüðümüz dizilerden ayýran, onlarý farklý kýlan özellikleri yoktur. örneðin bir tam sayý ( int ) dizisinde, 
tam sayýlarý saklarken; bir karakter dizisinde -yani katarda- karakterleri ( char ) saklarýz.

Stringlerle, daha önce gördüðümüz diziler arasýnda bir farkýn olmadýðýný söylemiþtik. Bu sözümüz, teorik olarak doðru olsa da, 
pratikte ufak tefek farklarý kapsam dýþý býrakýyor. 

Hatýrlayacaksýnýz, dizilerde elemanlara deðer atama ya da onlardan deðer okuma adým adým yapýlan bir iþlemdi. 

Genellikle bir döngü içersinde, her dizi elemaný için scanf(  ) veya printf(  ) fonksiyonunu çaðýrmamýz gerekiyordu. 

Katarlar için böyle bir mecburiyet bulunmuyor. 

Tek bir kelimeyi, tek bir scanf(  ) fonksiyonuyla okutabilir ve elemanlara otomatik deðer atayabilirsiniz. Yani "Merhaba" þeklinde bir girdi-input gelirse, 
3.dizi elemaný 'r' olurken; 6.dizi elemaný 'b' olur. 
Önceki dizilerde gördüðümüzün aksine, eleman atamalarý kendiliðinden gerçekleþir. Aþaðýdaki örneði inceleyelim:*/

#include<stdio.h>
int main(){
	
	char isim[30];
	printf( "Isim giriniz> ");
	scanf( "%s", isim );
	printf( "Girdiginiz isim: %s\n", isim );
	return 0;
}
/*Örneðimizde 30 karakterlik bir karakter dizisi tanýmlayarak iþe baþladýk. 

Bunun anlamý girdileri saklayacaðýmýz 'isim' katarýnýn 30 karakter boyutunda olacaðýdýr. 

Ancak bu katara en fazla 29 karakterlik bir kelime atanabilir. Çünkü katarlarda, kelime bitiminden sonra en az bir hücre boþ býrakýlmalýdýr.
 
Bu hücre 'Boþ Karakter' ( NULL Character ) tutmak içindir. Boþ karakter "\0" þeklinde ifade edilir. 

C programlama dilinde, kelimelerin bittiðini boþ karakterlerle anlarýz. Herhangi bir katarý boþ karakterle sonlandýrmaya, 'null-terminated' denmektedir.

Bu arada katarlara deðer atarken ya da katarlardan deðer okurken, sadece katar adýný yazmamýzýn yettiðini farketmiþsinizdir. 

Yani scanf(  ) fonksiyonu içersine & iþareti koymamýz gerekmiyor. Çünkü scanf(  ), katarýn ilk adresinden baþlayarak aþaðýya 
doðru harfleri tek tek atamasý gerektiðini biliyor.( Aslýnda biliyor demek yerine, fonksiyonun o þekilde yazýldýðýný söylememiz daha doðru olur. )

?? Aþaðýda bulunan kodun görevi nedir? */

#include<stdio.h>
int main()
{
	char isim[30];
	int i;
	printf( "Isim giriniz> "); // mustafa
	scanf( "%s", isim );

	printf( "Girdiðiniz isim: ");
	for( i = 0; isim[i]!='\0'; i++ )
		printf( "%c", isim[i] );
	printf("\n");

	return 0;
}

/*isim katarýnýn elemanlarý, "\0" yani boþ karakterere ( NULL Character ) eþit olmadýðý sürece yazdýrmaya devam edilmesidir. 
Ne zaman ki kelime biter, sýradaki elemanýn deðeri "\0" olur; iþte o vakit döngüyü sonlandýrmamýz gerektiðini biliriz.

Yukardaki örneðimize birden çok kelime girdiyseniz, sadece ilk kelimenin alýndýðýný farketmiþsinizdir. Yani "Bugün hava çok güzel." 
þeklinde bir cümle girdiðiniz zaman, katara sadece "Bugün" kelimesi atanýr. 
Eðer ayný anda birden fazla kelime almak istiyorsanýz, ayrý ayrý belirtilmesi gerekir. */

#include<stdio.h>
int main()
{
	char isim[25], soyad[30];
	printf( "Ad ve soyad giriniz> ");
	scanf( "%s%s", isim, soyad );
	printf( "Sayýn %s %s, hos geldiniz!\n", isim, soyad );
	return 0;
}

// gets(  ) ve puts(  ) Fonksiyonlarý

// Boþluk içeren bu tarz cümleler için puts(  ) ve gets(  ) fonksiyonlarý kullanýlmaktadýr.

#include<stdio.h>
int main()
{
	char cumle[40];
	printf( "Cumle giriniz> ");
	gets( cumle );
	printf( "Girdiginiz cumle:\n" );
	puts( cumle );
	return 0;
}

/* gets(  ) isminden anlayacaðýnýz ( get string ) gibi katara deðer atamak için kullanýlýr. 
puts(  ) ( put string ) ise, bir katarýn içeriðini ekrana yazdýrmaya yarar. gets(  ) atayacaðý deðerin ayrýmýný yapabilmek için '\n' aramaktadýr. 
Yani klavyeden Enter'a basýlana kadar girilen her þeyi, tek bir katara atayacaktýr. puts(  ) fonksiyonuysa, printf(  ) ile benzer çalýþýr. 
Boþ karakter ( NULL Character ) yani '\0' ulaþana kadar katarý yazdýrýr; printf(  ) fonksiyonundan farklý olarak sonuna '\n' koyarak bir alt satýra geçer. */


//Stringlere Ýlk Deger Atama

//Birinci yöntemle deðer atamasý yapacaksanýz, istediðiniz kelimeyi bir bütün olarak yazarsýnýz:

#include<stdio.h>
int main( void )
{
	// Her iki katarada ilk deger 
	// atamasi yapiliyor. Ancak 
	// isim katarinda, boyut 
	// belirtilmezken, soyad katarinda 
	// boyutu ayrica belirtiyoruz.
	char isim[] = "Mustafa";
	char soyad[5] = "Turan";
	printf( "%s %s\n", isim, soyad );

	return 0;
}

// Ýkinci yöntemdeyse, kelime bütün olarak yazýlmaz. Bunun yerine harf harf yazýlýr ve sonlandýrmak için en sonuna boþ karakter ( NULL ) eklenir:

#include<stdio.h>
int main( void )
{
	char isim[] = { 'M', 'U', 'S', 'T','A', 'F', 'A', '\0' };
	char soyad[6] = { 'T', 'U', 'R', 'A','N','\0' };
	printf( "%s %s\n", isim, soyad );
	return 0;
}


// Standart String Fonksiyonlarý

/* Katarlarla daha kolay çalýþabilmek için, bazý hazýr kütüphane fonksiyonlarýndan bahsedeceðiz. 
Bu fonkisyonlar, string kütüphanesinde bulunuyor. Bu yüzden, programýnýzýn baþýna, 
#include<string.h> eklemeniz gerekiyor.

1)  strlen(  ) fonksiyonuyla katar boyutu bulma

Dizi boyutuyla, katar uzunluðunun farklý þeyler olduðundan bahsetmiþtik. 
Dizi boyutu, 40 karakter olacak þekilde ayarlanmýþken, dizi içinde sadece 7 karakterlik "Merhaba" kelimesi tutulabilir. 
Bu durumda, dizi boyutu 40 olmasýna raðmen, katar boyutu yalnýzca 7'dir. 
Katarlarýn boyutunu saptamak için, boþ karakter ( NULL Character ) iþaretinin yani "\0" simgesinin konumuna bakýlýr. 
Her seferinde arama yapmanýza gerek kalmasýn diye strlen(  ) fonksiyonu geliþtirilmiþtir. 
strlen(  ) kendisine argüman olarak gönderilen bir katarýn boyutunu geri döndürür. Aþaðýdaki gibi kullanýlmaktadýr:*/


#include<stdio.h>
#include<string.h>
int main( void )
{
	printf( "Katar Uzunlugu: %d\n", strlen("Merhaba") );
	return 0;
}


/* 2) strcpy(  ) ve strncpy(  ) ile katar kopyalama

Bir katarý, bir baþka katara kopyalamak için strcpy(  ) fonksiyonunu kullanýrýz. Katarlar ayný boyutta olmak zorunda deðildir. 
Ancak kopya olacak katar, kendisine gelecek kelimeyi alacak boyuta sahip olmalýdýr. 
*/

char *strcpy( char[ ], char[ ] );


#include<stdio.h>
#include<string.h>
int main( void )
{
	char kaynak[40]="Merhaba Dunya";
	char kopya[30] = "";
	strcpy( kopya, kaynak );
	printf( "%s\n", kopya );

	return 0;
}

/* 3) strcmp(  ) ve strncmp(  ) ile katar karþýlaþtýrma

strcmp(  ) fonksiyonu, kendisine verilen iki katarý birbiriyle karþýlaþtýrýr. Katarlar birbirine eþitse, geriye 0 döner. 
Eðer ilk katar alfabetik olarak ikinciden büyükse, geriye pozitif deðer döndürür. 
Þayet alfabetik sýrada ikinci katar birinciden büyükse, geriye negatif deðer dönmektedir. 

strncmp(  ) için de ayný kurallar geçerlidir. Tek fark, karþýlatýrýlacak karakter sayýsýný girmemizdir. 
strcmp(  ) fonksiyonunda iki katar, null karakter iþareti çýkana kadar karþýlaþtýrýlýr. 
Fakat strncmp(  ) fonksiyonunda, baþlangýçtan itibaren kaç karakterin karþýlaþtýrýlacaðýna siz karar verirsiniz. */

#include<stdio.h>
#include<string.h>
int main(){
	int sonuc;
	char ilk_katar[40]="Kedi";
	char ikinci_katar[40]="Pasta";
	sonuc = strcmp( ilk_katar, ikinci_katar );
	printf( "%d\n", sonuc );
	sonuc = strncmp( ilk_katar, ikinci_katar, 3 );
	printf( "%d\n", sonuc );

	return 0;
}

/* 4) strcat(  ) ve strncat(  ) ile katar birleþtirme

strcat(  ) ve strncat(  ) fonksiyonlarý, bir katarý bir baþka katarla birleþtirmeye yarar. 
Fonksiyon adlarýnda bulunan cat, Ýngilizce bir kelime olan ve birleþtirme anlamýna gelen 'concatenate'den gelmiþtir. 
strcat(  ) kendisine verilen katarlarý tamamen birleþtirirken, strncat(  ) belirli bir eleman sayýsýna kadar birleþtirir. 
strcat ile ilgili basit bir örnek yapalým. */

#include<stdio.h>
#include<string.h>
int main(){
	char ad[30], soyad[20];
	char isim_soyad[50];
	printf( "Ad ve soyadinizi giriniz> " );
	scanf( "%s%s", ad, soyad );
	// isim_soyad <-- ad
	strcat( isim_soyad, ad );
	// isim_soyad <-- ad + " "
	strcat( isim_soyad, " " );
	// isim_soyad <-- ad + " " + soyad
	strcat( isim_soyad, soyad );
	printf( "Tam isim: %s\n", isim_soyad );
	return 0;
}

/* 5) strlwr() 

Bir dizindeki büyük harfleri küçük harflere çevirir. */

#include<stdio.h>
#include<string.h>
int main(){
	
	char kaynak[40]="Merhaba DUNYA";
	printf( "%s\n",  strlwr(kaynak) );

}

/* 6) strupr()

Bir dizindeki harfleri büyük harfe çevirir.*/


#include<string.h>
int main(  ){
	char kaynak[40]="Merhaba DUNYA";
	printf( "%s\n",  strupr(kaynak) );

}
