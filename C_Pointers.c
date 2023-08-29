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

    // isdigit(): girilen char rakamsa 1 de�ilse 0
    char rakam = '3';
    printf("isdigit('3'):%d\n",isdigit(rakam));

    // isalpha(): girilen char harfse 1 de�ilse 0
    char harf = 'h';
    printf("isalpha('h'):%d\n",isalpha(harf));

    // isalnum(): girilen char harf veya rakamsa 1 de�ilse 0
    printf("isalnum('3'):%d\nisalnum('h'):%d\n\n",isalnum(rakam),isalnum(harf));

    // islower(): girilen char k���k harfse 1 de�ilse 0
    printf("islower('h'):%d\nislower('H'):%d\n",islower(harf),islower('H'));

    // isupper(): girilen char b�y�k harfse 1 de�ilse 0
    printf("isupper('h'):%d\nisupper('H'):%d\n\n",isupper(harf),isupper('H'));

    // isspace(): girilen char bo�luk, \f, \n, \v, \t, \r ise 1 de�ilse 0
    printf("isspace(' '):%d\nisspace('h'):%d\n\n",isspace(' '),isspace(harf));

    // ispunct(): girilen char noktalama i�areti veya sembolse 1 de�ilse 0
    printf("ispunct(','):%d\nispunct('&'):%d\nispunct('h'):%d\n\n",ispunct(','), ispunct('&'),ispunct(harf));

    // tolower(): girilen char b�y�k harfse k���k harfe �evirir
    printf("tolower('H'):%c\n",tolower('H'));

    // toupper(): girilen char k���k harfse b�y�k harfe �evirir
    printf("toupper('h'):%c\n",toupper(harf));

    return 0;
}

// STRINGLER

/*
Dizileri ve �ok boyutlu dizileri g�rd�k. Katar dedi�imiz �ey de asl�nda bir dizidir.
 
De�i�ken tipi char yani karakter olan diziler, 'katar' ya da ingilizce ad�yla 'string' olarak isimlendirilirler.

Katarlar�, �imdiye kadar g�rd���m�z dizilerden ay�ran, onlar� farkl� k�lan �zellikleri yoktur. �rne�in bir tam say� ( int ) dizisinde, 
tam say�lar� saklarken; bir karakter dizisinde -yani katarda- karakterleri ( char ) saklar�z.

Stringlerle, daha �nce g�rd���m�z diziler aras�nda bir fark�n olmad���n� s�ylemi�tik. Bu s�z�m�z, teorik olarak do�ru olsa da, 
pratikte ufak tefek farklar� kapsam d��� b�rak�yor. 

Hat�rlayacaks�n�z, dizilerde elemanlara de�er atama ya da onlardan de�er okuma ad�m ad�m yap�lan bir i�lemdi. 

Genellikle bir d�ng� i�ersinde, her dizi eleman� i�in scanf(  ) veya printf(  ) fonksiyonunu �a��rmam�z gerekiyordu. 

Katarlar i�in b�yle bir mecburiyet bulunmuyor. 

Tek bir kelimeyi, tek bir scanf(  ) fonksiyonuyla okutabilir ve elemanlara otomatik de�er atayabilirsiniz. Yani "Merhaba" �eklinde bir girdi-input gelirse, 
3.dizi eleman� 'r' olurken; 6.dizi eleman� 'b' olur. 
�nceki dizilerde g�rd���m�z�n aksine, eleman atamalar� kendili�inden ger�ekle�ir. A�a��daki �rne�i inceleyelim:*/

#include<stdio.h>
int main(){
	
	char isim[30];
	printf( "Isim giriniz> ");
	scanf( "%s", isim );
	printf( "Girdiginiz isim: %s\n", isim );
	return 0;
}
/*�rne�imizde 30 karakterlik bir karakter dizisi tan�mlayarak i�e ba�lad�k. 

Bunun anlam� girdileri saklayaca��m�z 'isim' katar�n�n 30 karakter boyutunda olaca��d�r. 

Ancak bu katara en fazla 29 karakterlik bir kelime atanabilir. ��nk� katarlarda, kelime bitiminden sonra en az bir h�cre bo� b�rak�lmal�d�r.
 
Bu h�cre 'Bo� Karakter' ( NULL Character ) tutmak i�indir. Bo� karakter "\0" �eklinde ifade edilir. 

C programlama dilinde, kelimelerin bitti�ini bo� karakterlerle anlar�z. Herhangi bir katar� bo� karakterle sonland�rmaya, 'null-terminated' denmektedir.

Bu arada katarlara de�er atarken ya da katarlardan de�er okurken, sadece katar ad�n� yazmam�z�n yetti�ini farketmi�sinizdir. 

Yani scanf(  ) fonksiyonu i�ersine & i�areti koymam�z gerekmiyor. ��nk� scanf(  ), katar�n ilk adresinden ba�layarak a�a��ya 
do�ru harfleri tek tek atamas� gerekti�ini biliyor.( Asl�nda biliyor demek yerine, fonksiyonun o �ekilde yaz�ld���n� s�ylememiz daha do�ru olur. )

?? A�a��da bulunan kodun g�revi nedir? */

#include<stdio.h>
int main()
{
	char isim[30];
	int i;
	printf( "Isim giriniz> "); // mustafa
	scanf( "%s", isim );

	printf( "Girdi�iniz isim: ");
	for( i = 0; isim[i]!='\0'; i++ )
		printf( "%c", isim[i] );
	printf("\n");

	return 0;
}

/*isim katar�n�n elemanlar�, "\0" yani bo� karakterere ( NULL Character ) e�it olmad��� s�rece yazd�rmaya devam edilmesidir. 
Ne zaman ki kelime biter, s�radaki eleman�n de�eri "\0" olur; i�te o vakit d�ng�y� sonland�rmam�z gerekti�ini biliriz.

Yukardaki �rne�imize birden �ok kelime girdiyseniz, sadece ilk kelimenin al�nd���n� farketmi�sinizdir. Yani "Bug�n hava �ok g�zel." 
�eklinde bir c�mle girdi�iniz zaman, katara sadece "Bug�n" kelimesi atan�r. 
E�er ayn� anda birden fazla kelime almak istiyorsan�z, ayr� ayr� belirtilmesi gerekir. */

#include<stdio.h>
int main()
{
	char isim[25], soyad[30];
	printf( "Ad ve soyad giriniz> ");
	scanf( "%s%s", isim, soyad );
	printf( "Say�n %s %s, hos geldiniz!\n", isim, soyad );
	return 0;
}

// gets(  ) ve puts(  ) Fonksiyonlar�

// Bo�luk i�eren bu tarz c�mleler i�in puts(  ) ve gets(  ) fonksiyonlar� kullan�lmaktad�r.

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

/* gets(  ) isminden anlayaca��n�z ( get string ) gibi katara de�er atamak i�in kullan�l�r. 
puts(  ) ( put string ) ise, bir katar�n i�eri�ini ekrana yazd�rmaya yarar. gets(  ) atayaca�� de�erin ayr�m�n� yapabilmek i�in '\n' aramaktad�r. 
Yani klavyeden Enter'a bas�lana kadar girilen her �eyi, tek bir katara atayacakt�r. puts(  ) fonksiyonuysa, printf(  ) ile benzer �al���r. 
Bo� karakter ( NULL Character ) yani '\0' ula�ana kadar katar� yazd�r�r; printf(  ) fonksiyonundan farkl� olarak sonuna '\n' koyarak bir alt sat�ra ge�er. */


//Stringlere �lk Deger Atama

//Birinci y�ntemle de�er atamas� yapacaksan�z, istedi�iniz kelimeyi bir b�t�n olarak yazars�n�z:

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

// �kinci y�ntemdeyse, kelime b�t�n olarak yaz�lmaz. Bunun yerine harf harf yaz�l�r ve sonland�rmak i�in en sonuna bo� karakter ( NULL ) eklenir:

#include<stdio.h>
int main( void )
{
	char isim[] = { 'M', 'U', 'S', 'T','A', 'F', 'A', '\0' };
	char soyad[6] = { 'T', 'U', 'R', 'A','N','\0' };
	printf( "%s %s\n", isim, soyad );
	return 0;
}


// Standart String Fonksiyonlar�

/* Katarlarla daha kolay �al��abilmek i�in, baz� haz�r k�t�phane fonksiyonlar�ndan bahsedece�iz. 
Bu fonkisyonlar, string k�t�phanesinde bulunuyor. Bu y�zden, program�n�z�n ba��na, 
#include<string.h> eklemeniz gerekiyor.

1)  strlen(  ) fonksiyonuyla katar boyutu bulma

Dizi boyutuyla, katar uzunlu�unun farkl� �eyler oldu�undan bahsetmi�tik. 
Dizi boyutu, 40 karakter olacak �ekilde ayarlanm��ken, dizi i�inde sadece 7 karakterlik "Merhaba" kelimesi tutulabilir. 
Bu durumda, dizi boyutu 40 olmas�na ra�men, katar boyutu yaln�zca 7'dir. 
Katarlar�n boyutunu saptamak i�in, bo� karakter ( NULL Character ) i�aretinin yani "\0" simgesinin konumuna bak�l�r. 
Her seferinde arama yapman�za gerek kalmas�n diye strlen(  ) fonksiyonu geli�tirilmi�tir. 
strlen(  ) kendisine arg�man olarak g�nderilen bir katar�n boyutunu geri d�nd�r�r. A�a��daki gibi kullan�lmaktad�r:*/


#include<stdio.h>
#include<string.h>
int main( void )
{
	printf( "Katar Uzunlugu: %d\n", strlen("Merhaba") );
	return 0;
}


/* 2) strcpy(  ) ve strncpy(  ) ile katar kopyalama

Bir katar�, bir ba�ka katara kopyalamak i�in strcpy(  ) fonksiyonunu kullan�r�z. Katarlar ayn� boyutta olmak zorunda de�ildir. 
Ancak kopya olacak katar, kendisine gelecek kelimeyi alacak boyuta sahip olmal�d�r. 
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

/* 3) strcmp(  ) ve strncmp(  ) ile katar kar��la�t�rma

strcmp(  ) fonksiyonu, kendisine verilen iki katar� birbiriyle kar��la�t�r�r. Katarlar birbirine e�itse, geriye 0 d�ner. 
E�er ilk katar alfabetik olarak ikinciden b�y�kse, geriye pozitif de�er d�nd�r�r. 
�ayet alfabetik s�rada ikinci katar birinciden b�y�kse, geriye negatif de�er d�nmektedir. 

strncmp(  ) i�in de ayn� kurallar ge�erlidir. Tek fark, kar��lat�r�lacak karakter say�s�n� girmemizdir. 
strcmp(  ) fonksiyonunda iki katar, null karakter i�areti ��kana kadar kar��la�t�r�l�r. 
Fakat strncmp(  ) fonksiyonunda, ba�lang��tan itibaren ka� karakterin kar��la�t�r�laca��na siz karar verirsiniz. */

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

/* 4) strcat(  ) ve strncat(  ) ile katar birle�tirme

strcat(  ) ve strncat(  ) fonksiyonlar�, bir katar� bir ba�ka katarla birle�tirmeye yarar. 
Fonksiyon adlar�nda bulunan cat, �ngilizce bir kelime olan ve birle�tirme anlam�na gelen 'concatenate'den gelmi�tir. 
strcat(  ) kendisine verilen katarlar� tamamen birle�tirirken, strncat(  ) belirli bir eleman say�s�na kadar birle�tirir. 
strcat ile ilgili basit bir �rnek yapal�m. */

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

Bir dizindeki b�y�k harfleri k���k harflere �evirir. */

#include<stdio.h>
#include<string.h>
int main(){
	
	char kaynak[40]="Merhaba DUNYA";
	printf( "%s\n",  strlwr(kaynak) );

}

/* 6) strupr()

Bir dizindeki harfleri b�y�k harfe �evirir.*/


#include<string.h>
int main(  ){
	char kaynak[40]="Merhaba DUNYA";
	printf( "%s\n",  strupr(kaynak) );

}
