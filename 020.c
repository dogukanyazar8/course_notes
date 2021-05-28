/*

Ders20

Başlık Dosyası - Header File
Kod Dosyası - Implementation File

Bir başlık dosyasında ilk yapılması gerekilen işlem, o başlık dosyanın çoklu dahil edilmesine karşı koruma.
Multiple Inclusion Guard

Öyle senaryolar var ki, bir önlem alınmazsa, bir kod dosyası bir başlık dosyasını birden fazla kez include edebilir.
Bu durumda include edilen dosyadaki bildirimler iki kez include edilecek ve iki kez kaynak dosyaya yapıştırılacak. Bazı bildirim iki kez bildirimi sentaks hatasıdır.

struct data {
    int x, y;
};

struct data {
    int x, y;
};

Konvensiyon bu şekilde olabilir

#ifndef DUTILITY_H
#ifndef _DUTILITY_H_
#ifndef DUTILITY_INCLUDED

-----------------------------------------------

#ifndef DUTILITY_H
#define DUTILITY_H

#endif

Önişlemci programı buraya ilk kez girdiğinde bu makro henüz tanımlanmamış olduğundan, 
önişlemci ifndef endif bloğuna girecek, ardından bu makronun tanımı yapacak.

Önişlemci program ikinci kez bu bloğun içine giremeyecek, çünkü makro tanımlı olacak.

Bunun bir de derleyici eklentileri ile olan yolu var.

#pragma once

pragmalar standart değil. Örneğin Microsoft derleyicisinin pragmasıyla, GCC derleyicisinin pragması aynı olmayabilir.

-----------------------------------------------

Ayrıca aşağıdaki iki farklı koşullu derleme komutları aynı anlamı taşıyor.

1)

#ifndef DUTILITY_H
#define DUTILITY_H

#endif

2)

#if !defined DUTILITY_H
#define DUTILITY.H

#endif

-----------------------------------------------

#   stringification operator (string yapma, dizge yapma operatörü)
##  token pasting operator   (atom yapıştırma, atom birleştirme operatörü)
    defined operator         (defined) (Bir makroyu parametre olarak alıyor ve true - false değer üretiyor. Makro varsa, yoksa)


Dolayısıyla aşağıdaki iki farklı koşullu derleme komutları aynı anlamı taşıyor.

1)

#if defined (MAX)

#endif

#ifdef MAX

#endif

2)

#if !defined (MAX)

#endif

#ifndef MAX

#endif

Peki neden aynı anlama gelen iki ayrı yapı var. Çünkü birden fazla makroya bağlı olarak koşul oluşturmak.

#if !defined (MAX) && defined (MIN) //Önişlemci program, MAX makrosu tanımlı değilse ve MIN makrosu tanımlıysa, bu bloğun içine girecek.

#endif

Biz yazarken isteğimize, ihtiyacımıza göre yazabiliriz. 
Şirkette yazıyorsak kodlama stili, kodlama kılavunuza göre yazmamız gerekir.

Veya var olan standartlardan birini kullanıyorlar. Otomotiv veya havacılık endüstrisi gibi.

Bunun dışında özel firmaların standartları var. Google Coding Conventions, Amazon Coding Conventions gibi.

İlerideki bir derste inline fonksiyonları göreceğiz.

-----------------------------------------------

Bir modüldeki fonksiyonlar ve global değişkenler aslında iki kategoriye ayrılıyor.

1) Dışa açılan, yani diğer modüllerin de ismiyle kullanabileceği, onların kullanımına açılmış fonksiyonlar ve global değişkenler.
    Bunlara modüllerin external öğeleri deniliyor.

2) Dışarıya kapatılmış, client kodların doğrudan çağırmasını, kullanmasını istemediğimiz öğeler var. 
    Yani biz bunları implementasyon tarafında kullanacağız ama diğer modüller bunları kullanamayacak.

İşte bu ayrımı sağlayan, global düzeyde kullanılan static anahtar sözcüğü.

int x = 10;         -> Böyle bir global değişken, diğer modüllerin de erişimine açtığımız bir global değişken.

void func(int x)    -> Böyle bir fonksiyon, diğer modüllerin de erişimine açtığımız bir fonksiyon.
{

}

Ve bunların bildirimleri başlık dosyasında olması gerekiyor. 

Ama static anahtar sözcüğüyle bir global değişkeni tanımlarsak, 
static anahtar sözcüğü ile bir fonksiyonu tanımlarsak, buradaki static anahtar sözcüğünün yerel değişkenleri tanımlarken kullandığımız static anahtar sözcüğüyle bir ilgisi yok.

Buradaki statik anahtar sözcüğü, bu fonksiyonun sadece bu modül tarafından kullanılacağını, diğer modüller tarafından kullanılamayacağını anlatıyor.

static int x = 10;

static void func(int x)
{

}

Yazdığımız bazı fonksiyonların bildirimlerini dutility.h başlık dosyamıza ekliyoruz.

int ndigit(int);

int isprime(int);

Bazı durumlarda ekran çıktısını yavaşlatmak için bir gecikme sağlayacak bir fonksiyona ihtiyacımız var.
Bu fonksiyonun ismini sleep yapıyoruz ve parametre olarak milisaniye yapıyoruz.

void sleep(int millisecond);

void putline(void); //standart outputa bir satır çizgi yazacak.

void clear_input_buffer(void);

-----------------------------------------------

Şimdi dutility.c implemantasyon dosyasına geldik. Kod dosyamıza.
Bu dosyanın ilk yapması gereken işlem, kendi başlık dosyasını include etmek.
Çünkü bu dosyadaki kodların da, ilgili başlık dosyasındaki bildirimlere ihtiyacı olacak.

Dolayısıyla, başlık dosyasında yapmamız gereken ilk iş, çoklu dahil etmeye karşı koruma.
Bu o başlık dosyasıyla ilgili kod dosyası da, ilk yapmamız gereken iş include komutuyla kendi başlık dosyasın dahil etmek.

Bu kod dosyasında artık başlık dosyasında bildirdiğimiz fonksiyonların tanımları olacak.

Burada sleep fonksiyonunu yazarken, derleyimizin bize verdiği bir başlık dosyası var, bu standart değil, bunu da include etmemiz gerekiyor.

Bir çok projede, modüller arasında çoklu bir hizmet alma verme ilişkisi var. Mesela dutility modülü bir hizmet veriyor, şuana kadar Windows.h modülünden hizmet aldı.
Dolayısıyla projeyi oluşturan modüller arasında böyle bir çoklu hizmet alma ilişkisi var.

putline fonksiyonunu yazarken stdio başlık dosyasında bildirilen printf fonksiyonunu çağıracak, dolayısıyla bu başlık dosyasını da dahil ediyoruz.

Bu başlık dosyaların include edilmesi sırası önemli mi?

Çok ekstrem bir senaryo olmadığı sürece, bizi ilgilendiren bizim kullandığımız isimlerin hangi başlık dosyasında bildirilmişse, o başlık dosyalarının include edilmesi.

Ancak iki tane tipik konvensiyon var.

1 - Kaynak dosya içerisinde yukarıdan aşağıya doğru, kullanım sırasıyla ilgili.

Mesela ilk olarak sleep fonksiyonunu kullandık, Windows.h ilk include edilen dosya.
Sonrasında printf çağrısı yaptık, bunun için stdio.h başlık dosyasını dahil ettik.

-----------------------------------------------

DUTILITY.C

#include "dutility.h"
#include <Windows.h>
#include <stdio.h>

int ndigit(int val)
{
    if (val == 0)
        return 1;
    
    int digit_count = 0;

    while (val) {
        ++digit_count;
        val /= 10;
    }

    return digit_count;
}

int isprime(int val)
{
    if (val == 0 || val == 1)
        return 0;
    
    if (val % 2 == 0)
        return val == 2;
    if (val % 3 == 0)
        return val == 3;
    if (val % 5 == 0)
        return val == 5;
    
    for (int k = 7; k * k <= val; k += 2)
        if (val % k == 0)
            return 0;
    
    return 1;
}

void sleep(int millisecond)
{
    Sleep(millisecond);
}

void putline(void)
{
    printf("\n------------------------------------------------");
}

void clear_input_buffer(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ; //null statement
}

-----------------------------------------------

Şimdi bu modülden hizmet alan bir kod yazıyoruz.

-----------------------------------------------

#include <stdio.h>
#include "dutility.h"

int main()
{
    int low, high;
    int prime_count = 0;

    printf("Aralik degerlerini giriniz: ");
    (void)scanf("%d%d", &low, &high);

    for (int i = low; i <= high; ++i)
        if (isprime(i)) {
            if (prime_count && prime_count % 10 == 0)
                putline();
            printf("%d ", i);
            sleep(100);
            ++prime_count;
        }

    printf("\n%d asal sayi bulundu\n", prime_count);
}

*/

/*

Type Conversions - Tür Dönüşümleri

Öyle durumlar var ki, derleyici bizim kodumuz karşılığı bir işlem kodu üretmek için, bizim bazı ifadelerimizi farklı bir türden isimlendirilmemiş bir nesne olarak oluşturuyor.
Yani bir türden bir ifadeyi, arkaplanda biz görmesek de, bir nesne oluşturarak, bir bellek alanını kullanarak, başka türden değermiş gibi işleme sokuyor.

Derleyicinin bazı işlemlerinin yapılabilmesi için, derleme zamanında onun var olan türü yerine, başka bir türden ifade kullanmasna tür dönüşümü deniliyor.

ival + dval

Makine düzeyinde, bir gerçek sayı ile bir tam sayıyı toplamak gibi bir işlem yok.
İki tane aynı boyutta tam sayı toplanabilir veya iki tane gerçek sayı toplanabilir.

Yani toplama operatörünün operandları makine düzeyinde baktığımız zaman aynı veri formatından olması gerekiyor.
Bir çok programlama dilinde, başta C olmak üzere böyle de bir kod yazabiliyoruz.

//ival'in değeri 34, dval'in değeri 3.5 ise, 37.5 değerini elde ediyoruz.

Derleyici aslında, bir int ile bir double toplanmayacağı için, kendisi bir bellek alanında ival'i double türden bir değişken olarak temsil ediyor.
Gerçekten de bir nesne oluşturuyor. Kaynak kodda doğrudan ismi olmayan fakat çalışan kodda bir nesne kullanılması durumda, oluşturulan böyle nesnelere geçici nesne deniliyor.

yazdığımız kod: ival + dval;

derleyici: double temp = ival;

temp + dval

Derleyicinin belirli durumlarda bir işlemin yapılabilmesi için ürettiği böyle kodlara tür dönüşümü deniliyor.

Tür dönüşümü iki temel kategoriye ayrılıyor.

1) Implicit Type Conversion (Otomatik tür dönüşümü, Örtülü tür dönüşümü)

Derleyici, dilin kuralları gereği bize sormadan, bazı durumlarda bazı işlemlerin, yukarıdaki gibi bir işlemin yapılabilmesi için tür dönüşümü gerçekleştiriyor.
Biz bu dönüşümü yap diye bir talimat vermiyoruz, bu dönüşüm örtülü olarak yapılıyor.

Biz kodu yazıyoruz, dilin kuralları gereği bu dönüşüm kodunu oluşturuyor. Derleyici bize sormuyor, dilin kuralları burada bir dönüştürme yapılması gerektiği için bu dönüşümü yapıyor.

2) Explicit Type Conversion (Operatör kullanılmasıyla, derleyiciye talimat vererek)

Biz yukarıdakinin aksine, bir operatör kullanarak C dilinin sentaksıyla bir talimat vereceğiz.
Biz bunun int türden olduğunu biliyoruz fakat bu işleme int türden değil de, double türden bir değerle sokulmasını istiyoruz.

type-cast operator - tür dönüştürme operatörü

Bu konu neden çok önemli?

Tür dönüşümü yapıldığı ya da yapılmadığı için bir veri kaybının oluşması. Yani yanlış bir kodun yazılmış olması, programımızın beklentimizin dışında çalışması, bir tanımsız davranış oluşması.

Öyle durumlar var ki, tür dönüşümü yapılmadığı için biz veri kaybediyoruz ya da tanımsız davranış durumu oluşuyor.
Ya da tam tersi, biz dilin kuralları gereği orada bir tür dönüşümü uygulandığını bilmiyoruz, bunu bilmediğimiz için o dönüşüm yapılmayacakmış mantığıyla o kodu yazdık.
Fakat bu dönüşüm yapıldığı için, yazdığımız kod yanlış oldu.

-----------------------------------------------------------

#include <stdio.h>

int main()
{
    int x = -1;

    unsigned int y = 2;

    if (y > x)
        printf("Evet dogru!");
    else
        printf("Hayir yanlis!");
}


-----------------------------------------------------------

#include <stdio.h>

int main()
{
    char c = 178;

    if (c == 178)
        printf("Evet dogru!");
    else
        printf("Hayir yanlis!");
}

-----------------------------------------------------------

#include <stdio.h>

int main()
{
    float f = 1.7f;

    if (f == 1.7)
        printf("Evet dogru!");
    else
        printf("Hayir yanlis!");
}

-----------------------------------------------------------

Basit Aritmetik Dönüşümler

a + b
x > y

Binary bir işlem söz konusu olsun. Bu çarpma, çıkartma, toplama veya karşılaştırma da hatta koşul operatörü de olabilir.

Eğer binary operatörün, operandları farklı türlerdense, a'nın türü b'nin türünden farklıysa, ya da x'in türü y'nin türünden farklı, derleyici belirli kurallara göre tür dönüştürme kodu oluşturuyor.

Türlerin dereceleri var. Rank diyebiliriz. Her türün bir sıralaması var. Bu sıralama büyükten küçüğe doğru bir sıra izliyor.

Gerçek sayı türleri, tam sayı türlerinden daha büyük kabul ediliyor. Gerçek sayı türlerinin dereceleri aşağıdaki gibi sırayla gidiyor.

===========
long double
double
float
===========
long long
long
int
===========
short
char
_Bool

Bu rank dediğimiz özellik, tam sayı türleri için işaretli, işaretsiz ayrımı yapmıyor. Rank yani dereceleri, sıralamaları aynı.

a + b

Derleyici yukarıdaki gibi bir işlemde, operandlardan biri en yüksek rank olan, long double türündense, 
diğer operandı da long double türüne dönüştürüyor ve işlemi long double türünde yapıyor.

a = long double
b = int 

b -> long double türüne dönüştürülecek, ve işlem long double türünden yapılacak.

Eğer operandlardan biri, long double türünden değilse, bu sefer derleyici operandlardan birinin double olup olmadığına bakıyor.

Eğer operandlardan biri double ise, diğerini de double türüne dönüştürüyor. İşlemi double türünde yapıyor.

Eğer double türünden de operand yoksa, bu sefer de float türüne bakılıyor. Operandlardan biri, float türünden değilse, bu sefer derleyici operandlardan birinin float olup olmadığına bakıyor.
Operandlardan biri float ise, diğerini de float türüne dönüştürüyor. İşlemi float türünde yapıyor.

---------------

Operandlardan birisi long double mı? -> İşlemi long double türünde yap.

Operandlardan birisi double mı? -> İşlemi double türünde yap.

Operandlardan birisi float mı? -> İşlemi float türünde yap.

---------------

Eğer operandlardan biri gerçek sayı türünden değilse, derleyici operandlardan birinin int altı türlerden (short - char - _Bool) biri olup olmadığına bakıyor.
Eğer operandlar, short - char - _Bool türündense, o zaman bunları int türüne değiştiriyor.

Bu kurala tam sayıya yükseltme anlamında integral promotion deniliyor.

Asla bir operatörün operandı char - short - _Bool türünden işleme sokulamaz, bunlar işleme sokulmadan önce int türüne dönüştürülüyorlar.

Bu işlem uygulandıktan sonra, 
operandlardan biri long long mu, diğerini de long long yap.
operandlardan biri long mu, diğerini de long yap.

---------------

    char c1 = 5;
    char c2 = 7;

    c1 + c2 -> bu ifadenin türü nedir? bu ifadenin türü int.

Aynı şekilde, iki tane short türünü topladığımız zaman da int türünden değer elde ediyoruz.

C dilinde bir ifadenin türünün konsola yazdırılmasını sağlayan standart bir araç yok fakat C++ dilinde var.
Dolayısıyla bir ifadenin türünün C++ ile gösterebiliriz.

---------------

Bu konuyla alakalı örnekleri type_conversion.cpp adlı dosyada gerçekleştirdim.

#include <iostream>

int main()
{
    using namespace std;

    char c1 = 5;
    char c2 = 7;

    short s1 = 10;
    short s2 = 15;

    char c3 = 10;

    long double ld1 = 4.;
    double d1;

    double d2 = 5.;
    int i1 = 0;

    long l1 = 10.0;
    char c4 = 5;

    cout << typeid(c1 + c2).name() << "\n\n";	//char olan operandlar int türüne dönüştürülecek. char - char -> işlem int.

    cout << typeid(s1 + s2).name() << "\n\n";	//short olan operandlar int türüne dönüştürülecek. short - short -> işlem int.

    cout << typeid(c3).name() << "\n\n";		//herhangi bir dönüştürme yok.
    cout << typeid(+c3).name() << "\n\n";		//işaret operatörü. char olan operand int türüne dönüştürülecek. -> işlem int.

    cout << typeid(ld1 + d1).name() << "\n\n";	//double olan operand long double türüne dönüştürülecek. long - double -> işlem long double.

    cout << typeid(d2 + i1).name() << "\n\n";	//int olan operand double türüne dönüştürülecek. double - int -> işlem double.

    cout << typeid(l1 + c4).name() << "\n\n";	//char olan operand int türüne dönüştürülecek. long - int -> işlem long.
}

---------------

Rank'i yani derecesi yüksek olan türe dönüştürülüyor. Peki int ve unsigned int olduğunda ne olacak?

Burada int'in ve unsigned int'in rank'i aynı. 

Dilin kurallarına göre, eğer operandlar aynı rank'ten ise, fakat biri işaretli diğeri işaretsizse, tür dönüşümü işaretsiz yöne yapılır.

Mesela aşağıdaki ifadenin türü unsigned int.

int ival = 10;
unsigned int uval = 15;

ival + uval -> bu ifadenin türü unsigned int.

Benzer şekilde, operandlardan birisi long, diğeri unsigned long olsaydı.

long lval = 10;
unsigned long ulval = 10;

lval + ulval -> bu ifadenin türü unsigned long.

---------------

Rank'ler farklıysa, yani biri long diğeri int. Bu durumda yüksek olan rank'de işlem yapılıyor.
İşaretli int ile işaretli long'u işleme soktuğumuzda, bu işlem long türünde yapılacak.

İşaretler aynı, birinin rank'i diğerinden yüksekse, işlem yüksek olan rank'de yapılıyor.

---------------

Operandlardan biri işaretli, diğeri işaretsiz, rank'ler de farklı.

Bu durumda yüksek olan rank işaretsiz, diğeri işaretli ise, işlem işaretsiz olanda yapılacak.

Yani unsigned long ile int'i işleme soktuğumuzda, tür dönüşümü unsigned long'a yapılacak.

unsigned long + int -> burada işlem unsigned long türünde yapılır.

---------------

Operandlardan biri işaretli, diğeri işaretsiz, rankler de farklı.

Bu durumda yüksek olan işaretli, diğeri işaretsiz ise, eğer daha yüksek rank'deki tür, 
daha düşük rankdeki işaretsiz türün tüm değerlerini tutabilecek büyüklükte ise, o zaman işlem daha büyük rank'de olan işaretli türde yapılır.

Ama bazı derleyicilerde olduğu gibi yüksek rank'deki işaretli tür, diğer işaretsiz türün olası bütün değerlerini tutamayacak büyüklükte ise,
o zaman işlem daha yüksek rankdeki, işaretsiz türde yapılır.

long + unsigned int -> derleyicideki long türü 4 byte, unsigned int türü 4 byte ise, işaretli long türü, işaretsiz int türünün bütün değerlerini tutamaz.

Bu durumda işlem yüksek rank olan long türünde ama işaretsiz olarak yapılır.

long (4 byte) + unsigned int (4 byte) -> burada işlem unsigned long türünde yapılır.

long (8 byte) + unsigned int (4 byte) -> burada işlem long türünde yapılır.

---------------

Eğer işaretler aynı, rankler aynı ise bir tür dönüşümü yapılmayacak. 

    int ile int, unsigned int ile unsigned int, long ile long.

Eğer rankler farklı, işaretler aynı ise, işlem daha yüksek rankdeki türde yapılacak. 

    int ile long, long ile long long

Eğer rankler farklı, biri işaretli, diğeri işaretsiz ise, yüksek olan rank işaretsiz ise, işlem ranki yüksek olan işaretsiz türde yapılacak.

    unsigned long ile int

Eğer rankler farklı, Biri işaretli, diğeri işaretsiz ise, yüksek olan rank işaretli ise, 

a) Eğer yüksek rankde olan tür, düşük rankde olan türün tüm değerleri tutabilecek büyülükte ise, işlem yüksek rank'deki işaretli türünde yapılacak.
b) Eğer yüksek rankde olan tür, düşük rankde olan türün tüm değerlerini tutabilecek büyüklükte değil ise, işlem yüksek rank'in işaretsiz türünde yapılacak.

Mesela diyelim ki, GCC derleyicisinde long 8, unsigned int türü 4 byte -> işlem long türünde yapılacak.
Mesela diyelim ki, GCC derleyicisinde long 4, unsigned int türü 4 byte -> işlem unsigned long türünde yapılacak.

Dilin kuralları bu şekilde.

---------------

Aynı türden iki değeri işleme sokarsak (int altı türler değil), tür dönüşümü yapılmaz.

int / int -> int 

Bazı dillerde int türünü int türüne böldüğümüzde, gerçek sayı elde ediliyor fakat C dilinde böyle değil.

Bir tam sayıyı, bir tam sayıya bölerek, bir gerçek sayı elde etme şansımız yok.

    int x = 10;
    int y = 3;

    double dval = x / y;

    printf("%f", dval);

dval'e ilk değer olarak verdiğimiz değerin ya da atadığımız değişkenin double türden olması, işlemin double türde yapılacağı anlamına gelmiyor.

Eğer bölme işleminin operandlarından biri int, diğeri de bir sabitse, int türden bir sabit kullanmak ile double türden bir sabit kullanmak arasında büyük bir anlam farkı var.

    int x = 10;

    double dval = x / 3; //int'i int'e böldük, işlem int türünde. 

    printf("%f", dval);

    int x = 10;

    double dval = x / 3.; //int'i double'a böldük, işlem double türünde.

    printf("%f", dval);

---------------

İşaretli tam sayı türlerinde taşma tanımsız davranıştır.

Sistemdeki int türü 2 byte olsun, bu türün alabileceği değer aralığı [-32768 / 32767]

    int x = 1000;
    int y = 1000;

    x * y -> bu işlemin sonucu 1000000 olacağından bu 2 byte'lık int türünde tutulamaz.

Dolayısıyla burada bir tanımsız davranış var. Bu kodun programın çalışma zamanında ne olacağı belli değil.
Böyle bir kod kesinlikle yanlış, yapılan işlem toplama işlemi bile olabilirdi.

1000 * 1000 çarpıyorum, 16960 çıkıyor. 

Biz bu çarpma işlemini int türünden yapıyorsak, int türü 2 byte ise, tanımsız davranış. 

Bir çok işlemcide bu işlem şu şekilde yapılıyor.

Olması gereken değer 1000000. 1000000'un hexadecimal gösterimi F4240.

F4240 - 5 Hex Digit. 4 Byte
int türümüz 2 Byte, yüksek anlamlı hex digit kayboluyor. F4240 -> 4240 oluyor.

4240 -> 16960 çıkacaktır. 

---------------

int türden bir değişkenimiz var, bunu int türden bir sabitle çarpıyoruz.
int türü 2 byte - long türü 4 byte
burada int türü 2 byte olduğu için taşma riski yüksek, tanımsız davranış olacak taşarsa.
bunu nasıl daha güvenli yapabiliriz?

ival * 20

Eğer int türü 2 byte, long türü 4 bytesa, o zaman sabiti long türünden yaparsak, işlem long türünden yapılacak.

ival * 20L

---------------

Aynı tam sayı türünün, işaretlisi ve işaretsizi işleme sokulduğunda, işlem işaretsiz türde yapılır.

Bu durumda, eğer işaretli olan tür negatifse, işaretsiz türe dönüştürüldüğünde, negatifliği gidecek büyük bir tam sayı olarak işleme sokulacak.

Örnek kod:

#include <stdio.h>

int main()
{
    int x = -1;
    unsigned int y = 1;

    if (y > x) // y = unsigned int x = int -> rankler aynı, işlem işaretsiz int türünde yapılacak.
        printf("Evet dogru!");
    else
        printf("Hayir yanlis!");
}

yukarıdaki kodda, x'in yani -1'in binary gösterimi: -1 -> 1111 1111 1111 1111

Bu değer işaretsiz int türüne dönüştürüldüğünde, işaret biti ortadan kalkıyor ve sayının büyüklüğünün bir parçası oluyor.

Aslında biz burada fiilen -1 ile 1'i değil, 4 milyar 290 milyon küsürlük bir değer.

Peki derleyiciler bun durumu lojik kontrolden yakalar mı? Hemen her zaman yakalar.

//Warning	C4018	'>': signed/unsigned mismatch

Derleyicinin uyarı verdiği bir kodu commitlememeliyiz.

Ama bazı durumlarda, derleyici uyarı veriyor ama biz onu bilerek isteyerek yazdık. 
Böyle durumlarda false positive deniliyor.

---------------

Matematiğin notasyonuyla C dilinin notasyonu farklı. Bazı kodlama hataları bundan dolayı kaynaklanmaktadır.

-b / 2a -> notasyon bu şekilde, bu şekilde yazarsak aslında bu -b / 2 * a olur.

Başka örnek:

Matematikte çarpma işleminin değişme birleşme özelliği vardır. 

x * y * z

z * y * x

İkisi de aynı anlamdadır. Fakat C dilinde böyle değil çünkü işin içine tür giriyor.

int türü 2 byte olsun.

int x = 1000;
int y = 1000;
double z = 1.5;

x * y * z -> işlemin bir bu şekilde yapıldığını düşünelim
z * y * x -> işlemin bir de bu şekilde yapıldığını düşünelim

Burada operatör öncelik seviyesi ve öncelik yönü kurallarına göre işlemler şu şekilde yapılacak:

x * y * z -> (x * y) * z -> int ile int -> taşma olacak, veri kaybı olacak. tanımsız davranış.
z * y * x -> (z * y) * x -> double ile int -> işlem double olacak. bir veri kaybı olmayacak.

---------------
*/

/*

Atama Tür Dönüşümleri

Burada açık veya kapalı bir atama söz konusu.

Örneğin ilk değer verme sentaksıyla:

int a = b; -> Burada eğer initializer olan ifade, yani b, ilk değer verilen değişkenin türünden değilse, derleyici önce b ifadesini int türüne dönüştürecek.

---------------

Örneğin atama operatörünün kullanılması:

x = y; -> Burada x'in türü int olsun, y'nin türü int olmayan bir tür olsun. Atama öncesinde derleyici, int türden olmayan ifadeyi int türüne dönüştürecek. Ondan sonra atama kodunu yürütecek.

---------------

Örneğin fonksiyon çağırma ifadesiyle:

func(x); -> Burada func fonksiyonuna gönderilen argüman double türden olsun fakat func'ın parametre değişkeni double olmayan bir türden olsun.

Derleyici argüman olan ifadeyi, argümanın gönderildiği parametre değişkeninin türüne dönüştürecek.

---------------

Örneğin return ifadesiyle:

return y; -> Burada return ifadesinin türü int olsun fakat fonksiyonun geri dönüş değeri türü int olmayan bir tür olsun.

Derleyici return ifadesini, o fonksiyonun geri dönüş değeri türüne dönüştürecek.

---------------

Kurallar aynı. Ortada bir atama, kopyalama var. Her zaman bu durumda, tür dönüşümü kopyalamanın yapıldığı nesnenin türüne yapılıyor.

char = int -> int türden olan nesne, atamadan önce char türüne dönüştürülecek.

float = double -> double türden olan nesne, atamadan önce float türüne dönüştürülecek.

---------------

Peki bu durumun önemi nedir?

Büyük bir türden, küçük türe atama/kopyalama yaparsak, veri kaybetme riskimiz var.
Ayrıca burada bir tanımsız davranış yok, sadece veri kaybı var.

---------------

Örnekler:

char c;
int i = 987;

c = i;

İşaretli char türü, -128 / 127 değerlerini tutabilir. 987 değeri bu char türünde tutulamaz.

Bu durumda yüksek anlamlı bytelar kaybedilecek. 987'nin binary gösterimi -> 0011 1101 1011

Budalama yapıldığında -> 1101 1011 -> -37

Derleyiciler de büyük türden küçük türe atama ya da kopyalama yapıldığında uyarı mesajı verirler.

warning C4244: '=': conversion from 'int' to 'char', possible loss of data

---------------

Peki biz bu durumu, bilerek, isteyerek yapıyorsak, bunu yine de yazmamalıyız ama bunu yazmanın yolu tür dönüştürme operatörünü kullanmak.

Artık derleyici uyarı mesajı vermez, okuyan da bunu bilerek, isteyerek yaptığımızı anlar.

#include <stdio.h>

int main()
{
    char c;
    int i = 45;

    c = (char)i;

    printf("%d", c);
}

---------------

Küçük tam sayı türünden büyük tam sayı türüne, bir işaret farkı yoksa dönüşümde bir problem yok.

Eğer gerçek sayıdan bir değeri, tam sayı türünden bir değişkene aktarırsak, kopyalarsak, bu durumda en iyi ihtimalle sayının ondalık kısmını kaybederiz.

    double dval;
    int ival;

    printf("Bir gercek sayi giriniz: ");
    scanf("%lf", &dval);

    ival = dval;

    printf("ival = %d", ival);

Böyle bir kod yazmamalıyız. Eğer yazarsak, double türündeki dval değerinin ondalık kısmı atılır. Burada bir yuvarlama da yapılmaz.

Gerçek sayının tam sayı kısmı, tam sayı türünde tutulamayacak kadar da büyük olabilir.

Mesela yukarıdaki program için, 8765123456.7651 girişi bu şekilde yapalım. Double türü bu değeri tutabilir.

Ama ondalık kısmı kaybettiğimizde kalan kısım, int türünün tutabileceğinden daha büyük. Bu durum tanımsız davranıştır.

---------------

Peki, tam sayı kısmının int türünde tutabileceğini eminiz ve biz ondalık kısmı atmak istiyoruz. Ondalık kısım gitsin.

Bu durumda tür dönüştürme operatörünü kullanarak, bu kodu okuyanlara bunu bilerek, isteyerek yaptığımızı belirteceğiz.

Ayrıca derleyici uyarı mesajı da vermeyecek.

    double dval;
    int ival;

    printf("Bir gercek sayi giriniz: ");
    (void)scanf("%lf", &dval);

    ival = (int)dval;

    printf("ival = %d", ival);

---------------

Büyük gerçek sayı türünden, küçük gerçek sayı türüne yapılan dönüşümler. long double'dan double'a. double'dan float'a. long double'dan float'a.

Dolayısıyla böyle bir dönüşüm yaptığımızda, iki ayrı kaybımız olabilir.

Birinci kayıp, hassasiyet. Double türündeki değerimiz noktadan sonra 12 basamak tutabiliyor, Float türü ise 6 basamak tutabiliyor.

Biz double'dan float'a dönüşüm yaptığımızda hassasiyeti kaybediyoruz, o rakamları kaybediyoruz.

İkinci kayıp ise, mesela standartlara göre 10^308 gibi bir çarpan değeri tutabiliyorken, bu değer float türüne sığmayabilir.


int main()
{
    double dval = 22.4;
    float fval = 21.124; //warning C4305: 'initializing': truncation from 'double' to 'float'. double türünden bir sabiti, float bir değişkene ilk değer verdik.

    fval = dval; //warning C4244 : '=' : conversion from 'double' to 'float', possible loss of data
}

Derleyicinin yukarıdaki kod için verdiği uyarı mesajları

warning C4244: '=': conversion from 'double' to 'float', possible loss of data
warning C4305: 'initializing': truncation from 'double' to 'float'

---------------

Tam sayı türlerinde taşma durumu, işaretli türler için söz konusudur. İşaretsiz türler taşmaz.

x * y -> x ve y int türden olsun, bir taşma söz konusu olsun, bu tanımsız davranış.

Ama işaretsiz türlerde taşma olmaz ve bir tanımsız davranış da olmaz. İşaretsiz türlerde her zaman modüler aritmetikde işlem yapılır.

    unsigned int x = UINT_MAX;

    printf("x = %u\n", x);
    printf("x + 1 = %u\n", x + 1);

Ekran çıktısı:

x = 4294967295
x + 1 = 0

Dolayısıyla işaretsiz iki değerin, toplanması veya çıkartılmasıyla elde edilen değer, ilgili işaretli tam sayı türünün en büyük değeri + 1, örneğin 2^32, işlemin değerine bölümünden kalandır.

Örneğin x ve y işaretsi tam sayı türündense, int türü 2 byte ise, x * y değerinin 65536'ya bölümünden kalandır.

Buna güvenerek kod yazabiliriz. Burada ne bir kodlama hatası, ne bir tanımsız davranış var.

---------------

#include <stdio.h>

int main()
{
    int x = 20;
    int y = 10;
    double dval = 3;

    double d = (x > 10 ? y : dval) / 3;

    printf("d = %f\n", d);
}

(x > 10 ? y : dval) -> ilk operandın türü y = int ikinci operandın türü dval = double

O zaman buradan elde edilecek değerin türü double. Dolayısıyla bu ifadenin değeri double.

---------------

#include <stdio.h>

int main()
{
    char c = 178;

    if (c == 178)
        printf("Evet dogrudur!");
    else
        printf("Hayir yanlistir!");
}

Burada signed char türünden olan c değeri 178. alabileceği değer aralığı -128 / 127. if kontrol deyimiyle int türünden olan 178 sabitiyle karşılaştırılıyor. 

178 sabiti işaretli char türünde sığmayacağından dolayı if deyiminin sol operandı olan c'nin türü int'e terfi ediliyor.

c = 178 -> Binary gösterimi: 10110010 -> int türüne terfi edildiğinde -> 1111 1111 1011 0010 -> -78
178 sabitinin Binary gösterimi -> 0000 000 1011 0010 -> 178

Biz aslında, if kontrol deyiminde -78 ile 178'i karşılaştırıyoruz. Değerler aynı olmadığı için if'in else kısmına girecektir.
---------------

Eğer char türünden olan c değerinin, aynı türde bir değerle işleme sokulmasını istiyorsak, tür dönüştürme operatörünü kullanabiliriz aşağıdaki gibi.
Bu sefer if'in doğru kısmına girecektir. Çünkü iyi aynı değeri karşılaştırıyor.

#include <stdio.h>

int main()
{
    char c = 178;

    if (c == (char)178)
        printf("Evet dogrudur!");
    else
        printf("Hayir yanlistir!");
}

*/
