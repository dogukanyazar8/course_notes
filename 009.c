/* 

Ders9

Standart C Library (Standart C Kütüphanesi)

Giriş - Çıkış İşlemleri

Output Stream
Input Stream

Standart Giriş Akımı
Standart Çıkış Akımı

Giriş Çıkış işlemleri aşağıdaki gibi iki farklı yapıda olabiliyor.

Formatlı Çıkış İşlemi
Formatsız Çıkış İşlemi

Bellekteki bitlerden ve bytelardan yola çıkarak, kullanılan sistemdeki karakter kodlamasına göre karakterlerin kod numarasını elde edeceğiz.
Bu maliyetli bir işlemdir, programın çalışma zamanında yapılacaktır.

Bellekte tutulan bir veriyi, insanın anlayacağı formatta, karakter kodlarına dönüştürerek dış dünyaya aktarmak, formatlı çıkış işlemidir.

Formatsız çıkış işlemi de, bellekteki bytelar ne ise, onları karakter kodlarına dönüştürmeden, olduğu gibi aktarılır. 
Örnek olarak iki cihazın haberleşmesi, insanın anlayacağı bir çıkışa gerek yoktur.

Giriş çıkış işlemlerini sağlayan standart C kütüphanesi
<stdio.h>

Formatlı çıkış işlemi sağlayan standart c kütüphanesi fonksiyonlarının sonunda F harfi vardır.

f: formatted

printf
fprintf
sprintf
snprintf

Format, formatlamak ne demek? Bir verinin formatlanması, o verinin insanın tercihlerine, istenilen şekline göre düzenlenmesidir.

Tam sayıların yazımında, hangi sayı sisteminde yazılacağı, sayı tabanın gösterilip gösterilmeyeceği, harf karakterlerinin büyük veya küçük yazılması, pozitif değerler için + karakteri yazılacak mı.
Bunların hepsi formatlama özelliğidir.

Yazma alanı genişliği
Output width

Doldurma karakteri
Fill character

Yazma Alanı Genişliği içerisindeki karakterlerin oryantasyonu, sağa dayalı, sola dayalı ya da internal biçimde oluşturabiliriz.

Internal (İşaretler ve Sayılar Alt Alta Geliyor)

+       567
-      2000

4564454 Doğukan Yazar
144 Soner Yazar
44 Ezgi Yazar
1123 Ticen Yazar

4564454 Doğukan Yazar
144.... Soner Yazar
44..... Ezgi Yazar
1123... Ticen Yazar

Gerçek sayıların yazdırılmasında da formatlama işlemleri kullanılır.
Noktadan sonra kaç basamak gösterilsin,
Nokta işareti gösterilsin mi,

Gerçek Sayıların Formatlanması

Fixed Notation      2323.56123  (10 üzeri çarpanı biçimde gösterilmiyor)
Scientific Notation 4.3         (10 üzeri çarpanı biçiminde ifade etmek)

C++'ın standart giriş çıkış işlemleri kütüphanesindeki yaklaşımı nesne yönelimli programlama yaklaşımı,
C'nin standart giriş çıkış işlemleri kütüphanesindeki yaklaşımı ise alt seviyeli bir yaklaşım söz konusu. 

Alt Seviye Avantajları:     ++Maliyet. Alt seviye, verimlilik, hakimiyet.
Alt Seviye Dezavantajları:  --Hata yapma riski çok yüksek.

----------------------------------------------------------------------------------------------------------

En sık kullanılan formatlı çıkış fonksiyonu: printf fonksiyonu

printf fonksiyonunun bildirimi <stdio.h> içerisindedir. 

int printf(const char *p, ...);

... -> ellipsis atomu

printf variadic bir fonksiyondur.

Variadic fonksiyona çağrı yapılırken uyulması gereken kural,

ellipsis ifadesi karşılığına dilediğimiz kadar parametre gönderebiliriz.

const char *p, 

bazı fonksiyonların parametre değişkenleri pointer, yani bu fonksiyonlar bizden adres istiyor. 

array (dizi)

int a[10];  

C dilinde diziyi bir fonksiyona göndermenin tek yolu call by reference. Diziler call by reference ile fonksiyonlara aktarılmalıdır.
Fonksiyonun parametre değişkeni pointer değişkeni olacak, biz de dizinin adresini göndereceğiz. Tek Yol: CALL BY REFERENCE

C dilinde bir fonksiyon, dizi üzerinden işlem yapmak için yazılmışsa en az bir tane parametresi pointer değişkeni olmak zorundadır. 
Bazı fonksiyonların parametre değişkenileri pointer ve bunlar bizden fonksiyona dizinin adresini göndermemizi istiyorlar.

Bir çok programlama dilinde yazılar, yazı türünü tutan değişkenler vardır.

string s = "arpeggio";

Fakat C dilinde yazılar char türünden dizilerde tutulur.

char str[100];

int printf(const char *p, ...);

printf fonksiyon bildirimindeki ilk parametrenin char *p türünden olması, bu parametrenin bizden bir char dizinin, bir yazının adresini istediği anlamına geliyor. 
Bu bir pointer parametre değişkeni.

const: pointer parametreler iki şekilde olabiliyor. 
ilkinde, o diziye bir değer göndermek veya o değeri değiştirmek.
ikincisinde ise o diziye salt okuma izni elde etmek.

void func(int *ptr);        //buradaki amaç nesneyi değiştirmek
void func(const int *ptr);  //buradaki amaç nesneyi değiştirmek değil

'B'
'A'
'B'
'A'
'\0' -> yazının bittiğini anlatan null ifadesi.

printf'in geri dönüş değeri tamamlayıcı bir bilgidir. standart output'a gönderilen karakter sayısıdır.

int val = printf("dogukan");

printf ile bir ya da birden fazla ifadenin değerini dilediğimiz formatlama özellikleriyle standart output'a yazdırabiliriz.

printf'in birinci parametresine gönderdiğimiz yazıda, % karakteri başlayan karakter başka bir anlama geliyor. escape sequence

printf'in formatlama notasyonu. 

convertion specifier
%d -> işaretli int türden bir değeri 10'luk sayı sisteminde ekrana yazdırma
%lf
%f
%i
%zu

% işaretini yazdırırken de %% kullanıyoruz.

%d - 10luk sayı sistemi
%o - 8lik sayı sistemi
%x - 16lık sayı sistemi
%f - float veya double türleri
%ld - long türü
%c - karakter

%c'yi bir tam sayıyla eşlersek, o tam sayıyı karakter kodu olarak alacak ve o karakteri yazdıracak.

printf yazma alanı genişliği, formatlama özellikleri

%2d
%-2d

printf("%d + %d + %d = %d", x, y, z, x + y + z);

gerçek sayı yazdırırken

for (int i = 0; i < 100; ++i)
{
    printf("%d sayisinin karekökü %f", i , sqrt(i));
}

scanf fonksiyonu

scanf fonksiyonun amacı, kaynak kodumuzdaki nesnelerimizi, standart inputdan gelen değerlerle eşlemek

int age;

scanf("%d", &age)

1: formatlı giriş fonksiyonudur

değişkenlerimizi set edecek, değer yükleyecek, bu yüzden scanfe gönderdiğimiz argümanın adres olması gerekiyor
call by reference

scanf fonksiyonunun geri dönüş değeri başarı bilgisidir.

%d
%o
%x

standart giriş akımının bir bellek alanı vardır. buffer - tampon

scanf'in işini bitirmesi için standart inputun bufferına new line karakteri gelmesi gerekiyor.
line buffered function 

standart inputun bufferına yazdığımız karakterlerin kodları bir diziye yazılıyor.
234BABA45

2: 50
3: 51
4: 52
B: 66
A: 65
B: 66
A: 65
4: 52
5: 53

scanf, standart inputun bufferından kullandığımız formatlama özelliklerine göre bu karakterlerden kullanabileceklerini kullanıyor.

234BABA45

scanf %d ile aldığımızda, 234 karakterlerini alacak. (abstract)
BABA45 karakterleri ise bufferda durmaya devam edecek.

scanf'in işini doğru yapma garantisi yok.

scanf'in geri dönüş değeri set ettiği alan sayısını dönüyor.

Bazı derleyicilerde scanf kullanırken derleyiciler uyarı verebilir.

scanf kullanma onun yerine scanf_s kullan
scanf'in pointer güvenliği olmadığı ve yanlış kullanma olasılığı olduğu için.

unix tabanlı işletim sistemlerinde standart inputun bufferını belirli bir tuş kombinasyonuyla boş bıraktığımızdad, scanf hata olarak -1 hata kodunu dönüyor.
-1 = standart inputun bufferında karakter yok hata kodu.

*/

/*

#include <stdio.h>

void func(int, int, ...);

int main()
{
    func(11); // sentaks hatası, fonksiyon bildirimindeki parametre sayısı kadar argüman göndermeliyiz.
    func(11, 22);
    func(11, 22, 33);
    func(11, 22, 33, 44, 55, 66, 77, 88);
}

#include <stdio.h>

int main()
{
    char str[100];
    printf(str);
}

*/

/*

#include <stdio.h>

int main()
{
    int x, y;
    
    printf("2 sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("%d * %d + %d * %d = %d", x, x, y, y, x * x + y * y);
}

*/

/*

#include <stdio.h>

int main()
{
    int x;
    
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);

    printf("decimal: %d - octal: %o - hex: %x", x, x, x);
}

*/

/*

#include <stdio.h>

int main()
{
    int ival = 65;

    printf("Karakter Kodu: %d Karakter: %c", ival, ival);
}

*/

/*

#include <stdio.h>

int cube(int a)
{
    return a * a * a;
}

int main()
{
    for(int i=0; i<100; i++)
    {
        printf("%2d -> %2d\n", i, cube(i));
    }
}

#include <stdio.h>

int max3(int a, int b, int c)
{
    int max = a;
    
    if (b > max)
        max = b;
    if (c > b)
        max = c;
        
    return max;
}

int main()
{
    int x, y, z;
    
    printf("3 Sayi Giriniz: ");
    scanf("%d%d%d", &x, &y, &z);
    
    printf("En buyuk sayi: %d", max3(x, y, z));
}

int main()
{
    int x = 987;
    
    printf("%d", printf("%d", printf("%d", x)));
}

#include <stdio.h>

int main()
{
    int ival;
    double dval;
    
    printf("Bir sayı giriniz: ");
    scanf("%d", &ival);
    scanf("%lf", &dval);
    
    printf("%d - %lf", ival, dval);
}

#include <stdio.h>

int main()
{
    char str[100];
    printf("Bir yazı giriniz: ");
    scanf("%s", str);
    printf("Girdiginiz yazi: %s", str);
}

#include <stdio.h>

int main()
{
    int x;
    char str[100];
    
    while (1)
    {
        printf("Lutfen bir tamsayi giriniz: ");
        int retval = scanf("%d", &x);

        if (retval == 1)
            break;
        
        scanf("%s", str);
        printf("Girdiginiz %s bir tam sayi degildir. Tekrar giriniz: ", str);
    }
    
    printf("Girdiginiz sayi: %d", x);
}

#include <stdio.h>

int main()
{
    int x;
    printf("Bir sayi giriniz: ");
    int retval = scanf("%d", &x);

    printf("Scanf Donus Degeri: %d", retval); // ctrl - z / d
}

#include <stdio.h> // Standart giriş akımının tamponunu nasıl boşaltabiliriz?

void clar_input_buffer(void)
{
    int c;
    
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int x, y;
    printf("Bir tam sayi giriniz: ");
    scanf("%d", &x);
    printf("Bir tam sayi daha giriniz: ");
    clar_input_buffer();
    scanf("%d", &y);

    printf("X = %d\n", x);
    printf("Y = %d\n", y);
}

*/

/*

OPERATORLER - OPERATOR (İşleç)

Derleyici kaynak kodu en küçük parçalarına ayırırken tokenizing yapıyor.
Bu token identifier, bu token specifier, bu token constant gibi kategorilere ayırıyor.
Operatörler ise kaynak kodda işlem yapılmasını sağlayan tokenlardır.

Her programlama dilinin operatörleri farklıdır, dilin tasarımıyla ilgilidir.

C dilinde 45 tane operatör vardır.
Bazıları tek karakterlik tokenlar: + ! ~ & * 
Bazıları iki karakterlik tokenlar: ++ >= >> << != ==
Bazıları üç karakterlik tokenlar: >>= <<=

sizeof (kendisi bir anahtör sözcük fakat dildeki işlevi bir operatör)

Operatörlerin işleme soktuğu ifadelere operand(terim) denir.

a + b (+ operator, a ve b operand)

!x (! operator, x operand)

Operatörün operand sayısını belirleyen terimler

Unary Operator (tek operand alan operatör)

!x ++y

Binary Operator (iki operand alan operator)

x + y, x % y

Ternary Operator (Direkt olarak Üç operand değil de, direkt olarak bir operatörün ismi Ternary)
Conditional Operator diye de geçiyor. Koşul operatörü.

?   : (Üç Operandlı)

Temel programlama dilleri bir çok operatörleri C dilinden almıştır.

Operatör ve Operandının konumsal ilişkisi:

Prefix  Ön Ek Konumunda         !x
Postfix Son Ek Konumunda        y++
Infix   Ara Ek Konumunda        a + b 

Operand sayısını niteleyen terimlerle, konumları niteleyen terimler birlikte kullanılır.

Unary Prefix. Unary Postfix. Binary Infix.

Operator kısıtlamaları (Constraint)

Operatör kullanımının geçerli olabilmesi için yazdığımız ifadenin dilin kurallarına göre bazı koşulları sağlaması gerekir.

Bazı operatörlerin operandları gerçek sayı olamıyor.

% (Modulus Operator)

a % 5 (Örnek olarak bu operatörün operandları gerçek sayı türünden olamaz)

double dval = 3.4;

dval % 2; (LEFT OPERAND TYPE IS DOUBLE, ILLEGAL)

Bazı operatörlerin operandları ise L value expression değer kategorisinde olması gerekiyor.

Örnek olarak atama operatörü. =

int x = 24;

12 = x; (EXPRESSION MUST BE A MODIFIABLE L VALUE EXPRESSION)

veya

x + 3 = 34;

Operatör bir işlem yapılmasını sağlıyor ve bu işlemin sonucunda ürettiği bir değer var.

operator generate, yield, return
operatörün ürettiği değer

C dilinde her operatörün ürettiği bir değer vardır.
Bazı operatörler tek bir token olmasına rağmen hem binary hem de unary olarak kullanılabilir.
Derleyici veya okuyucu, bunların ne anlama geldiğini ifade içerisinde kullanılan operand sayısından anlıyor.

    a & b   bitwise and
    &x      address of
    
    x * y   multiplication
    *ptr    dereferencing
    
    a + b   addition
    +x      sign operator
    
    x - y   subtraction
    -a      sign operator

OPERATOR ONCELIGI
       
a + x / *ptr > 10 -> Hangi ifade hangi operatorun operandı??

Operatör önceliği bir işlemin fiziksel olarak daha önce ya da daha sonra yapılacağı anlamına gelmiyor.

Operatör önceliği, birden fazla operatör içeren ifadelerde gruplamaya ilişkin kurallardır.

(a + (x / (*ptr))) > 10 

*/


