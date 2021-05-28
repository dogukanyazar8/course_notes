/* 

Ders7

C programlama dilinde fonksiyon çağrısı operatör seviyesinde bir işlemdir.

fonksiyon çağrı operatörü
function call operator()

function designator (fonksiyonun ismi)

function call expression (fonksiyon çağrı ifadesi)

func()

C dilinde fonksiyon yüklemesi yoktur.
Function overloading.

Kodları farklı olsa bile birden fazla fonksiyonun aynı isimde olması.

C'de bütün fonksiyonlarının isimlerinin farklı olması gerekir.

default argument (varsayılan argüman)

Fonksiyon çağırısında eksik argüman girilemez.

Geri dönüş değeri olmayan (void) fonksiyonlara çağrı yaptığımızda onu bir değere atayamayız. 
; ile statement haline getirebiliriz.

Geri dönüş değeri olan bir fonksiyona yapılan çağrı ifadesi hangi biçimlerde kullanılabilir?
1) Fonksiyonun geri dönüş değerini bir değişkene atamak.
2) Fonksiyonun geri dönüş değerini bir değişkene ilk değer olarak vermek.

Fonksiyonun geri dönüş değeri kullanmamak lojik bir hatadır.

to discard the return value of a function

Neden bir fonksiyonun geri dönüş değerini bir değişkende saklıyoruz?
a) bu değeri kaynak kodda birden fazla yerde kullanmak için

scope leakage (kapsam sızıntısı)

//gereksiz yere kullanım
{
    int nx = ndigit(x); 
    int ny = ndigit(y);

    if (nx + ny > 5)
    ++a;
}

{
    if (ndigit(x) + ndigit(y) > 5)
    ++a;
}

if (ndigit(a) > max(x,y))
{

}

Bir fonksiyon çağrısının argümanı, başka bir fonksiyon çağrısı olabilir.

sqrt(max(x,y))

sqrt(max2(ndigit(x), ndigit(y)))

Kodun okunmasını zorlaştırmayacak şekilde istenildiği kadar kullanılabilir.

strcat(strcopy(s1,s2), s3)

Fonksiyonların return deyimi bir fonksiyon çağrısı olabilir.

return ndigit(max(x, y));

---------------------------------------------------------------------

CALL BY VALUE (değerle çağrı)
Fonksiyona bir nesne gönderiliyor, bu nesnenin değerini kullanılıyor, bir kopyası oluşturuluyor ve onunla işlem yapılıyor.

CALL BY REFERENCE (referansla çağrı)
Fonksiyona nesnenin kendisi gönderiliyor, istenilirse bu nesnenin değeri değiştirilebilir.

C dilinde bütün fonksiyonların çağrıları CALL BY VALUE çağrılardır. Değerle çağrılardır.
C++ dilinde ise bunu anlayabilmek için fonksiyonun kendisine bakmak gerekir.

C dilinde bir fonksiyona nesnesinin kendisinin gönderilmesi adres semantiğiyle oluyor.
Call by reference iile bir nesneyi çağırmak için o nesnenin pointer türünden olması gerekir.
Adres operatörü ile çağrılabilir.

Nesnenin değerinin gönderilmesi CALL BY VALUE.
Nesnenin kendisinin gönderilmesi CALL BY REFERENCE.

C dilinde default olan ise CALL BY VALUE.

Ek bir örnek olarak, scanf fonksiyonuna yaptığımız çağrılar call by reference çağrılardır.

scanf("%d", &ival);

*/

//call by value

/* 
#include <stdio.h>

void func(int a)
{
    a = 999;
}

int main()
{
    int x = 10;

    printf("X: %d\n", x);
    func(x);

    printf("X: %d\n", x);
} */

//call by reference

/* 
#include <stdio.h>

void func(int *a)
{
    *a = 999;
}

int main()
{
    int x = 10;

    printf("X: %d\n", x);
    func(&x);

    printf("X: %d\n", x);
} 

Bir fonksiyona, fonksiyon çağrısında fonksiyonun parametre değişkeninden daha az veya daha fazla argümanla çağrı yapılamaz. 
Sentaks hatasıdır. Geçersiz bir kod oluşur.

Variadic Function
Variadik fonksiyon, böyle fonksiyonlara çağrı yapan kod istediği kadar argüman gönderebilir.
Çağıran kod belirli kurallar dahilinde dilediği kadar argüman gönderebilir.

printf
fprintf
sprintf
scanf
sscanf
fscanf

ellipsis tokenı (üç nokta atomu) (variadik fonksiyonlarda kullanılır)
ellipsis sadece son parametre değişkeni olabilir.
ellipsis atomundan önce en az bir tane parametre değişkeni olması gerekir.

void func(int x, int y, ...) 
{
    ///code
}

int main()
{
    func(10, 20);
    func(10, 20, 40);
    func(10, 20, 40, 50, 60);
}

//formatted output function
örnek olarak printf() fonksiyonu

int printf(const char *p, ...);

---------------------------------------------------------------------

SABİTLER / CONSTANTS - LITERALS
STANDART C KÜTÜPHANESİNE GİRİŞ
FORNATLI GİRİŞ ÇIKIŞ İŞLEMLERİ
OPERATÖRLER
KONTROL DEYİMLERİ

---------------------------------------------------------------------

derleyici, derlemenin ilk sürecinde kaynak kodu tokenlarına ayırıyor ve kategorize ediyor.
tokenizing.

keyword
identifier
constant
operator
string literals
delimeter

C dilinde sabitler iki ana gruba ayrılıyor.

Integer Constants
    signed int
    unsigned int
    signed long int
    unsigned long int
    signed long long int
    unsigned long long int

Floating Constants
    float
    double
    long double

C ve C++ dillerinde sabitlerin türleri vardır.

int
unsigned int
*/
