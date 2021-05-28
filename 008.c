/*

Ders8

Sabitler (Constants)

Integer Constants (tam sayı sabitleri)
    int (charachter literals)
    unsigned int
    long
    unsigned long
    long long
    unsigned long long
Floating Constants (gerçek sayı sabitleri)
    float
    double
    long double

C dilinde sabitlerin yazımında 3 farklı sayı sistemini kullanabiliyoruz. (Sabitin türü değil! Sayı sistemi!)
    Decimal
    Octal
    Hexadecimal

Öyle alanlar var ki, bu alanlarda varsayılan olarak hexadecimal veya octal sayı sistemleri kullanılıyor.
Örnek olarak mikroişlemcilerin adreslenmesinde hexadecimal sayı sistemi kullanılıyor.

Tam Sayı Sabitleri

int x = 41;     //Decimal
int y = 041;    //Octal
int z = 0x41;   //Hexadecimal

16'lık sayı sisteminin yazımı

0X41 veya 0x41. Harfler küçük de olabilir büyük de. (en iyisi - ya hepsini büyük, ya da hepsini küçük yazmaktır.)

Derleyiciler, standart C dilinin kurallarının yanı sıra, programcının işini kolaylaştırmak için standart olmayan araç ya da araçlar da sunuyorlar.
Bu öğelere derleyici eklentileri deniliyor. Compiler Extensions

+GCC derleyicisinin eklentileri.

Mesela, C dilinde ikilik sayı sisteminde bir sabit yazılamaz fakat derleyici eklentisiyle yazılabilir. (C++'da ise ikilik sayı sistemi standart.)

Örnek olarak: int x = 0b1100101;

int x = 87'321'784; // C dilinde derleyici etklentisi olabilir, C++ dilinde standart

--------------------------------------------------------------------------------------------------------

Eğer yazılan bir tam sayı sabiti sistemin işaretli int türünü sınırını aşmıyorsa türü int türüdür. (sabitlerin türü taşmıyorsa default olarak int)


2147483647 -> Sabitin türü int.
2147483648 -> Sabitin türü unsigned long.

50000 - Bu sabitin türü nedir?
Cevap: Impletation Defined.

0x1ac4 - Bu sabitin türü nedir?
Cevap: int (çünkü sistemdeki int sınırlarını taşmıyor)

unsigned int türünden sabitler. U harfi küçük veya büyük olabilir.

642u;
542U;
0X12u;
0156U;

long türünden sabitler. L harfi küçük veya büyük olabilir fakat küçük harf kullanmamak lazım çünkü "1 ile l" karıştırılabilir.

45L;
39l;
0x65L;
04234L;

unsigned long türünden sabitler. UL harfi küçük veya büyük olabilir, harflerin sırası da önemli değil.

46UL;
46LU;

long long türünden sabitler. LL harfi küçük veya büyük olabilir, harflerin sırası da önemli değil.

55LL;
55ll;

unsigned long long türünden sabitler. ULL harfi küçük veya büyük olabilir.

55ULL;
55LLU;

Ek olarak 0 da bir sabittir. Sıfırın da türü vardır.

0;
0U;
0UL;
0LL;

--------------------------------------------------------------------------------------------------------

Taşma durumunda ne olur?

Eğer yazılan sabit bir son ek içermiyorsa ve int türünü aşıyorsa, sabitin türü bu durumda hangi sayı sisteminde yazıldığında da bağlı
    
    Eğer taşan sabit, 10'luk sayı sisteminde yazılmışsa

    int'e sığmadı,
    long'a sığmadı,
    unsigned long'a sığmadı,
    long long'a sığmadı,
    unsigned long long

    Eğer taşan sabit, 8'lik veya 16'lık sayı sisteminde yazılmışsa

    int'e sığmadı,
    unsigned int'e sığmadı,
    long'a sığmadı,
    unsigned long'a sığmadı,
    long long'a sığmadı,
    unsigned long long

    4976123871u -> Sonunda U son eki olduğunda, taşsa da unsigned olmak zorundadır.

------------------------------------------------------------------------------------------------


Gerçek Sayı Sabitleri

Eğer bir sabit nokta içeriyorsa varsayılan olarak sabitin türü double'dır.

Sabiti 34.4 olarak yazıyoruz fakat bilgisayar bunu bize 34.39999999999 gibi bir şekilde gösteriyor. Bu neden?

Biz 34.4 gerçek sayı sabitini yazıyoruz fakat double sayı formatında bunun karşılığını elde etmek tam olarak mümkün değil.

Mantissa alanındaki bit sayıları toplandığında tam olarak 34.4 yapmıyor. 34.4'e en fazla bu şekilde yaklaşabiliyoruz.

34.;
34.0;
0.52;
.52;
.4;

Gerçek sayı sabitinin float türü olması için küçük veya büyük harf f - F eki alması gerekiyor.

34.8F;
22.4f;
0.f;
762f;   -> sentaks hatası. nokta içermiyor.

8;      int
8L;     long
8.;     double
8.L;    long double

Gerçek sayı sabitlerinin yazımında kullanılan notasyona üstel notasyon diyoruz. (Scientific Notation)

2.7 * 10^4

2.7e3
2.7E-5

3E4
3e4
23e-4

2.6e3;
2E4;

#include <stdio.h>

int main()
{
    3E4;
    2.6E3;
    2E4;   
    1.2E-3;

    float f = 1.4;

    if (f == 1.4)
    {
        printf("Dogru!\n");
    }
    
    else
        printf("Yanlis!\n");       

    return 0;
}

#include <stdio.h>

int main()
{
    double dval = 0.;

    for (int i = 0; i < 10; ++i)
        dval += 0.1;
    printf("dval = %f\n", dval);

    if (dval == 1.) {
        printf("Evet Dogru!\n");
    } else {
        printf("Hayır Yanlis!\n");
    }
}

Yukarıdaki iki program da programın çalışma zamanında yanlış kısmına girecektir. Gerçek sayı aritmetiği, tam sayı aritmetiği gibi değildir.

------------------------------------------------------------------------------------------------

Karakter Sabitleri

int türden sabitlerin bir alt kategorisidir, sabitlerin bir yazım biçimidir.

C dilinde karakter sabitlerinin türü int türüdür.
C++ dilinde karakter sabitlerinin türü char türüdür.

'A'
'D'
'+'

Escape Sequence 

'\n'
'\45'
'\145'

Karakter Kodlaması (Character Encoding)

ASCII
UNICODE
EBCDIC

'A'

A karakterinin karakter kodlamasında kullanılan B karakterinin kod numarası. Karakter kodlama sistemlerinde her bir karakterin bir kod numarası vardır. (Coding Place)

ASCII karakter kodlamasında 128 tane karakter vardır.

7 Bitli

0 - 127

Bu karakter kodlamasında büyük harfler ve küçük harfler tek bir blokta değil. Büyük harf karakterleri bittikten 6 karakter sonra küçük harf karakterleri geliyor.

Aralarında 6 karakter var. Neden?

Aradaki farkı 32'ye çekmek için. Böylece bir karakter kodunu tutan değişkenin 5. bitini 0'layarak veya 1'leyerek,
Aynı karakterin büyüğünden küçüğüne, küçüğünden büyüğüne dönüşüm yapmayı en hızlı şekilde gerçekleştirmek için.

Örnek olarak ASCII karakter kodlamasındaki 66 kod numarasının karşılığı büyük harf B harfidir. Karakter kod numarasına 32 eklersek, küçük harf b harfini buluruz. 98 - b

Büyük harf karakterleri: 26 tane (Hex 41'den başlıyor)

65  A
66  B
.....
90  Z

97  a
98  b
99  c

Rakam Karakterleri: Decimal 48 (Hex 30'dan başlıyor)
    Tüm karakter kodlama sistemlerinde rakam karakterlerinin ardışık olma garantisi verilmiştir. Yani buna güvenilerek kod yazılabilir. Ardışık olmak zorundadır.

48  0   0011 0000
49  1   0011 0001
50  2   0011 0010

2'nin kod numarasının 2'lik sayı sisteminde yazılması durumunda düşük anlamlı nibble: 2
Yani bir rakam karakterinin kodunun, düşük anlamlı nibble'ı, değer olarak o rakamın kendisi.

7   55  0011 0111 -> (0111) Düşük Anlamlı Nibble 7

Bu karakterlerin yerleştirilme biçimi tesadüf değildir.

Alpabetic       Character (Harf Karakterleri)
Numeric         Character (Rakam Karakterleri)
Alphanumeric    Charahter (Alpabetic + Numeric)

Printable / Graphic Character (Görüntüsü olan karakterler)
Control Character (Görüntüsü olmayan, özel amaçlar için kullanılan karakterler)
Printable fakat Alphanumeric değil -> Punctuation Character (. , " ' ! { [ ] } ")

ASCII karakter kodlamasında 0 dahil, 31 dahil, bu aradaki 32 karakter kontrol karakteridir, 127 yani son karakter de kontrol karakteridir.

*/

/* ASCII Karakter Kodlamasıyla İlgili C Programı

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("ascii.txt", "w");
    if (!f) {
        fprintf(stderr, "dosya olusturulamadi!\n");
        return 1;
    }

    for (int i = 0; i < 128; ++i)
    {
        if (iscntrl(i))
        fprintf(f, "%-3d %2X    KONTROL KARAKTERI\n", i, i);
        else
        fprintf(f, "%-3d %2X    %c\n", i, i, i);
    }

    fclose(f);
}

*/

/* Girilen Karakterin ASCII Kod Numarasını Gösteren Uygulama

#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;

    printf("Bir karakter girin: ");
    c = getchar();

    printf("%c karakterinin kod numarası %d\n", c, c);
}

*/ 

/*

#include <stdio.h>

int main()
{
    int x = '?';

    printf("X = %d", x);
}

-----------------------------------------------------------------------------------------------------

*/


/*

Escape Characters (\)

\ karakteri, ters bölü karakteri, karakterlerin sabitlerinin yazdırılmasında escape olarak kullanılıyor.

escape sequence (3 ayrı escape sequence biçimi vardır)

'\a'    alert (bell) (çan sesi)
'\b'    backspace (geri boşluk)
'\n'    new line 
'\r'    carriage return
'\t'    horizontal tab
'\v'    vertical tab
'\f'    form feed
'\0'    null character
'\?'    question mark
'\''    single quote
'\"'    double quote
'\\'    backslash

Karakter sabitinin hexadecimal sayı sisteminde yazılması.

'\x1a'
'\x41'
'\x7B'
'\x2E'

Karakter sabitinin octal sayı sisteminde yazılması.

'\103'
'\76'
'\134'

Karakter sabiti demek, karakter sabitleriyle oluşturulmuş bir dizi demektir.

"\x42URS\x41\n" (BURSA)

\102\101\102\101\012" (BABA)

/* escape sequence karakterlerinin ASCII kodunun yazdırılması

#include <stdio.h>

int main()
{
    printf("new line            %d\n", '\n');
    printf("carriage return     %d\n", '\r');
    printf("horizontal tab      %d\n", '\t');
    printf("vertical tab        %d\n", '\v');
    printf("form feed           %d\n", '\f');
    printf("backspace           %d\n", '\b');
    printf("alert               %d\n", '\a');
    printf("single quote        %d\n", '\'');
    printf("double quote        %d\n", '\"');
    printf("double quote        %d\n", '"'); 
    printf("null character      %d\n", '\0');
    printf("backslash           %d\n",  '\\');
}

*/

/*

#include <stdio.h>

int main()
{
    printf("\x42URS\x41\n");
    printf("\x4b\x4f\x53\x45\x44\x45\x20\x4b\x41\x46\x41\x4e\x41\x20\x41\x54\x41\x52\x49\x4d");
    printf("\102\101\102\101\012");
}

*/

/*

Standart Kütüphaneye Giriş

Standard C Library

C'nin standartları tarafından garanti altına alınmış, derleyicilerin sağlamakla yükümlü olduğu bileşenler. 

Standart C Fonksiyonları, bu kütüphanenin en önemli bir bileşeni.

Standard C Function
Standard Macros
Standard Type Alias
Standard User Defined Types

1 - Common Interface
2 - Code Reuse
3 - Portability

Common Interface: Standart kütüphane, ortak bir arayüz sağlıyor. Her şey aynı şeye baktığında aynı bilgiyi elde ediyor, aynı şeyi anlıyor, algılıyoruz. 

sqrt(abs(x))

strcat(strcpy(s1, s2), s3)

Yazılmışı Var!: Profesyonel düzeyde yazılmış, test edilmiş, derleyiciler tarafından optimize edilmiş standart kodları kullanabiliyoruz.

Taşınabilirlik: Standart kütüphaneden bir fonksiyon çağırdığımızda, bu fonksiyonun kodu farklı işletim sistemleri için farklı yazılmış olabilir, nasıl yazıldığı bizi ilgilendirmiyor.

Standart C kütüphanesi farklı alt modüllerden oluşuyor. 

Örnek olarak matematik ile ilgili hizmet veren fonksiyonlar math.h isimli kütüphanenin bileşenleri.
Giriş çıkış işlemleri stdio.h
Yazılarla ilgili işlemler string.h
Karakterle ilgili işlemler ctype.h

C++ dilinde ise stdio.h => cstdio

Ön işlemleri komutlarında herhangi bir kütüphane bileşenini include ettiğimizde ilgili fonksiyonların tanımları gelmiyor.
Fonksiyonların tanımları yok, kodları yok. Sadece fonksiyon bildirimleri var. Bu fonksiyonlar kodlanmış, derlenmiş. Biz derlenmiş kodları kullanıyoruz.
Derleyici programlarda bu kodların object kodları var.

int printf(const char*, ...)

Variadik fonksiyonlar istenildiği kadar parametre ile çağrılabilir.

int func(int x, ...); 

... (ellipsis)

*/

/* 1'den 100'e kadar olan sayıların kareköklerini standart çıkış akımına gönderen program.

#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        printf("%3d %f\n", i, sqrt(i));
    }
}

*/

/* A üzeri B işlemini hesaplayan program

#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;
    printf("Iki gercek sayi giriniz: ");
    scanf("%lf%lf", &x, &y); // C dilinde bütün fonksiyon çağrımları call by reference. 
    printf("%f ==> %f = %f\n", x, y, pow(x, y));
}

*/

/*

#include <stdio.h>
#include <math.h>

int main()
{
    int tamSayi;
    printf("Bir tam sayı giriniz: ");
    scanf("%d", &tamSayi);
    printf("%d sayisinin mutlak degeri: %d", tamSayi, abs(tamSayi));
}

*/

/*

Giriş Çıkış İşlemleri (1) - Input Output Operations

Program söz konusu olduğunda, programın dış dünyayla olan ilişkisini anlatan işlemlerdir.

Program çalıştığında, dış dünyayla bir veri alış verişinde olabilir. 

Programımıza gelen byte'lar.    Giriş Kaynağı:Input Stream      Keyboard, File, Network, Program
Programımızdan giden byte'lar.  Çıkış Kaynağı:Output Stream     Console, File, Network, Program

*/

