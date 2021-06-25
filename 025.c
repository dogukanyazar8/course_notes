/*

Özel, başka bir yöntem kullanılmıyorsa, herkesin kullandığı yöntem yazının karakterlerinin kodlarının bir char dizide tutulması.
Ve yazının son karakterinden sonra null karakterin bulunması.

char str[100];

C11 standartlarıyla _s olan fonksiyonların verilip verilmemesini derleyicinin kararına bırakmış.
gets_s fonksiyonu Visual Studio 2019 versiyonunda verilmemiş.

Ayrıca gets isimli fonksiyon C'nin C99 standartlarıyla kullanımdan kaldırıldı, C11 standartlarıyla dilden silindi.

----

remove_copy algoritması -> bir veri yapısından, belirli öğeler yokmuş gibi bu veri yapısındaki öğeleri başka bir veri yapısına kopyalamak.
remove algoritması -> bir veri yapısındaki bir elemanı bulunduğu yerden silmek.

----

Copy Algorithm - Kopyalama Algoritması

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char source[SIZE];
    char dest[SIZE];

    printf("Bir yazi giriniz: ");
    sgets(source);

    int i;

    for (i = 0; source[i] != '\0'; ++i){
        dest[i] = source[i];
    }

    dest[i] = '\0';

    printf("[%s]\n", source);
    printf("[%s]\n", dest);
}

----------

SORU: Aşağıdaki while döngüsü deyimi, source dizisindeki elemanları dest dizine kopyalar mı? Herhangi bir hata var mıdır*

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char source[SIZE];
    char dest[SIZE];

    printf("Bir yazi giriniz: ");
    sgets(source);

    int i = 0, k = 0;

    while (dest[i++] = source[k++])
        ;

    printf("[%s]\n", source);
    printf("[%s]\n", dest);
}

Cevap: 

Atama operatörünün ürettği değer nesneye atanan değerdir. 
Son ek ++ operatörünün ürettiği değer nesnenin kendi değeridir. 
Yazının dogukan olduğunu düşünelim, döngünün ilk turunda 'd' yi kopyalayacak, atama operatörünün ürettiği değer d'nin değeri. 0 olsaydı döngüden çıkacaktı, non zero olduğu için devam edecek.
Döngünün sondan bir önceki turunda null karakter de kopyalanacak. Fakat son turda atama operatörünün ürettiği değer, null karakterin değeri 0 olduğu için döngüden çıkacak.
Sorunun cevabı, hiçbir problem yok.

while (dest[i++] = source[k++])
while ((dest[i++] = source[k++]) != '\0')

Kodu iki şekilde de yazabiliriz. Hiçbir farkı yok.

---

Remove Copy Algoritması - Sourcedaki yazıyı Dest'e kopyalayacağız ama Sourcedaki karakter silinecek karakterse, bunu kopyalamayacağız.

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char source[SIZE];
    char dest[SIZE];

    printf("Bir yazi girin: ");
    sgets(source);

    int c;
    printf("Silinecek karakteri girin: ");
    c = getchar();

    int i, k;

    for (i = 0, k = 0; source[i] != '\0'; ++i) {
        if (toupper(source[i]) != toupper(c))
            dest[k++] = source[i];
    }

    dest[k] = '\0';

    printf("%s\n", source);
    printf("%s\n", dest);
}

-------

Remove Copy Algoritması - While Döngüsüyle

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char source[SIZE];
    char dest[SIZE];

    printf("Bir yazi giriniz: ");
    sgets(source);

    int c;
    printf("Silinecek karakteri giriniz: ");
    c = getchar();

    int read_idx = 0;
    int write_idx = 0;

    while (source[read_idx] != '\0'){
        if (source[read_idx] != c) {
            dest[write_idx++] = source[read_idx];
        }
        ++read_idx;
    }

    dest[write_idx] = '\0';

    printf("%s\n", source);
    printf("%s\n", dest);
}

--------

Remove Copy Algoritması - Tek Bir Dizi Kullanarak

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Bir yazi girin: ");
    sgets(str);
    
    int c;
    printf("Silinecek karakteri girin: ");
    c = getchar();

    int read_idx = 0, write_idx = 0;

    while (str[read_idx] != '\0') {
        if (toupper(str[read_idx]) != toupper(c)) {
            str[write_idx++] = str[read_idx];
        }
        ++read_idx;
    }

    str[write_idx] = '\0';

    printf("[%s]\n", str);
}

-----

Yazıların eşitliğini kontrol etmek 1

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str1[SIZE];
    char str2[SIZE];

    printf("Bir yazi girin: ");
    sgets(str1);
    
    printf("Bir yazi daha girin: ");
    sgets(str2);

    int i = 0, k = 0;
    int flag;

    while (str1[i] != '\0'){
        if (str1[i++] != str2[k++]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Yazilar esit!\n");
    else
        printf("Yazilar esit degil!\n");
}

-----

Yazıların eşitliğini kontrol etmek 2

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str1[SIZE];
    char str2[SIZE];

    printf("Ilk yaziyi girin: ");
    sgets(str1);

    printf("Ikinci yaziyi girin: ");
    sgets(str2);

    int i = 0, flag = 0;

    while (str1[i] == str2[i]){
        if (str1[i] == '\0'){
            flag = 1;
            break;
        }
        ++i;
    }
    if(flag)
        printf("Yazilar esit\n");
    else
        printf("Yazilar esit degil\n");
}

--------

Yazıdan sadece rakam karakterlerini silmek

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Bir yazi girin: ");
    sgets(str);

    int read_idx = 0, write_idx = 0;

    while (str[read_idx] != '\0') {
        if (!isdigit(str[read_idx])) {
            str[write_idx++] = str[read_idx];
        }
        ++read_idx;
    }

    str[write_idx] = '\0';
    printf("[%s]\n", str);
}

--------

Yazıdaki kelimeleri saymak

Bu tür soruların en kolay çözümü basit bir durum bilgisi tutmak.
Ne zaman yeni bir kelime ile karşılaşıyorum? 
-> Eğer boşluk karakterinden sonraki karakter boşluk karakteri değilse, yani yazıyı dolaşırken bir önceki karakter boşluk karkateriyken bir sonraki karakter boşluk karakteri değilse, kelimenin dışından kelimenin içine girmiş olacağız.
Bu durumda bir sayacı arttırmamız lazım.
-> Eğer boşluk karakteri değilse, fakat bir önceki karakter yine boşluk karakteri değilse, sayacı arttırmayacağız. 

word_flag isimli bir bayrak değişken kullanıyoruz. -> yazıyı dolaşırken kelimenin içinde miyiz, dışında mıyız bilgisini verecek.
Bayrak değerlerini de makro olarak tanımlıyoruz.

OUTWORD
INWORD

Eğer yazıyı dolaşırken word_flag'in değeri OUTWORD ise, kelimenin dışındayım.
Eğer yazıyı dolaşırken word_flag'in değeri INWORD ise, kelimenin içindeyim.

word_flag'in ilk değeri OUTWORD olmalı.

Bir de kelime sayısını tutmak için word_count isimli bir değişken kullanıyoruz.

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100
#define OUTWORD 0
#define INWORD 1

int main()
{
    char str[SIZE];
    printf("Bir yazi girin: ");
    sgets(str);

    int word_flag = OUTWORD;
    int word_count = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (isspace(str[i])) {
            word_flag = OUTWORD;
        }
        else if (word_flag == OUTWORD){
            ++word_count;
            word_flag = INWORD;
        }
    }

    printf("Kelime sayisi: %d\n", word_count);
}

---------

Yazıdaki kelimeleri bulmak

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    printf("Bir yazi girin: ");
    sgets(str);

    int word_flag = 0;
    int word_count = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (!isalnum(str[i])){
            word_flag = 0;
        }
        else if(word_flag == 0){
            ++word_count;
            word_flag = 1;
        }
    }

    printf("Kelime sayisi: %d\n", word_count);
}

------

Girilen yazı palindrom mu değil mi

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    char temp[SIZE];

    printf("Bir yazi girin: ");
    sgets(str);

    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i){
        if (isalpha(str[i]))
        temp[len++] = str[i];
    }

    int i;

    for (i = 0; i < len / 2; ++i){
        if (toupper(temp[i]) != toupper(temp[len - 1 - i]))
            break;
    }

    if (i == len / 2)
        printf("Palindrom\n");
    else
        printf("Palindrom degil\n");
}

-----

Derleyicilerin tipik olarak gerçekleştirdiği lojik kontroller

Derleyicilerin switchleri var. Eğer derleyiciyi komut satırından çağırıyorsak, bu switchleri orada veriyoruz.
Fakat Visual Studio gibi bir IDE'den derleyicinin switchlerini düzenleyebiliyoruz.
Bu switchler derleme işlemini özelleştiriyor, daha custom hale getiriyor.
Optimizasyon switchleri, uyarı switchleri.

Genellikle programcıların aşağıdaki gibi bu switchleri kullanması isteniliyor.

Tread warnings as errors: Eğer bunu seçersek, bize obje dosya oluşturmayacak. 
Uyarı falan vermeyecek, doğrudan sentaks hatası verecek.

Derleyiciler birbirlerinden farklı olabilir ama uyarı mesajları konusunda aynı davranıyorlar.

------

Lojik Uyarı Mesajları

1) Değişkeni tanımladık fakat hiç kullanmamak

Örnek Kod:

#include <stdio.h>

int main()
{
    int x;
}

GCC Uyarı Mesajı

warning: unused variable 'x' [-Wunused-variable]

2) Otomatik ömürlü yerel bir değişkeni çöp değeriyle kullanmak

Örnek Kod:

#include <stdio.h>

int main()
{
    int x;

    int y = x + 5;
}

GCC Uyarı Mesajı

warning: 'x' is used uninitialized in this function [-Wuninitialized]

3) Tür dönüşümlerine ilişkin mesajlar - Veri kaybına yol açan dönüşümler

Örnek Kod 1:

#include <stdio.h>

int main()
{
    double dval;
    int ival;
    scanf("%lf", &dval);

    ival = dval;
}

Örnek Kod 2:

#include <stdio.h>

long long foo(void);

int main()
{
    int x = foo();
    printf("%d\n", x);
}

Microsoft Derleyicisi Uyarı Mesajı

conversion from 'double' to 'int', possible loss of data

---

Örnek Kod 3:

#include <stdio.h>

long long foo(void);

int main()
{
    int x = foo();
    printf("%d\n", x);
}

Microsoft Derleyicisi Uyarı Mesajı

truncation from 'double' to 'float'

4) If kontrol deyiminin veya döngü deyimlerinin koşul ifadesinde karşılaştırma operatörü yerine atama operatörünü kullanmak.

#include <stdio.h>

int main()
{
    int ival;
    scanf("%d", &ival);

    if (ival = 5) {

    }
}

Microsoft Derleyicisi Uyarı Mesajı

assignment within conditional expression

5) Bir fonksiyon kodunda return deyiminin olmaması

Örnek Kod 1:

int func(int x)
{
    if (x > 10)
        return x;
    if (x == 5)
        return 12;

    //burada return yok. programın akışı buraya geldiğinde bu fonksiyon çöp değer döndürecek.
}

Örnek Kod 2:

int func(int x)
{
    x += 10; 
}

Microsoft Derleyicisi Uyarı Mesajı

'func' : must return a value

5) Bir fonksiyonun geri dönüş değerini hiç kullanmamak

Aşağıdaki kodda dutility.h başlık dosyasında bildirilen isprime isimli asal sayı test fonksiyonunu çağırdık fakat geri dönüş değerini kullanmadık.
Derleyiciler bu fonksiyonun geri dönüş değerini kullanmamanın lojik bir hata olup olmadığını bilemez. 

Örnek Kod:

#include <stdio.h>
#include "dutility.h"

int main()
{
    int ival;
    printf("Bir sayi girin: ");
    scanf("%d", &ival);

    isprime(ival);
} 

C++'da bu durum için, dilin kurallarıyla belirlenmiş standart bir araç var.

dutility.h başlık dosyasındaki, isprime fonksiyonunun geri dönüş değerinin türünün yazılmasından önce [[nodiscard]] attribute'unu yazıyoruz.
Bunun anlamı şu, eğer bu fonksiyonun geri dönüş değeri kullanılmazsa, derleyici uyarı mesajı ver anlamındadır.
Şimdi artık bu durum, derleyicinin insiyatifine kalmış bir durum değil.

[[nodiscard]] int isprime(int);

Aşağıdaki örnek kodu .cpp olarak yazıp, ilgili fonksiyona başlık dosyasından nodiscard attribute'unu eklediğimizde lojik uyarı mesajı verecektir.

Örnek Kod:

#include <stdio.h>
#include "dutility.h"

int main()
{
    int ival;
    printf("Bir sayi girin: ");
    scanf("%d", &ival);

    isprime(ival); // dutility.h başlık dosyasındaki bildirimi ->>> [[nodiscard]] int isprime(int);
} 

GCC Uyarı Mesajı

warning: 'nodiscard' attribute directive ignored

C dilinde ise bu maalesef standart değil. Derleyicilerin neredeyse hepsi bir eklenti olarak bize C++'dakine benzer bir araç sunuyor. Tabi bu bir extension.
Derleyiciye göre bu şekilde bir bildirim yapılabilir. ->>> __nodis int isprime(int);

Bazı fonksiyonları da derleyici implicit olarak nodiscard özelliğiyle tanımlamış olabilir. 
Mesela scanf fonksiyonunu çağırdığımızda gelen uyarı mesajı. scanf'in geri dönüş değerini kullanmadık diye. Çünkü derleyicimiz scanf'i içsel olarka nodiscard olarak almış.

Böyle durumlarda biz fonksiyonun geri dönüş değerini bilerek isteyerek kullanmıyorsak derleyiciye ve kodu okuyana bunu anlatmak için ilgili fonksiyonu void türüne cast edeceğiz.

(void)getchar(); ->>> Bu fonksiyonun geri dönüş değerini bilerek isteyerek discard ettim.

-------

Ayrıca, özellikle Microsoft derleyicisinde scanf fonksiyonunu çağırdığımızda, derleyici bu fonksiyonun oluşturduğu pointer hatası riskine karşı, 
2011 standartlarıyla gelen alternatif bir fonksiyon olan scanf_s'i kullanmamız bilgisini lojik uyarı mesajı olarak veriyor. 
Veya bu uyarı mesajını görmek istemiyorsan, _CRT_SECURE_NO_WARNINGS makrosunu define edebilirsin bilgisini de veriyor.

_s olan fonksiyonlar, safe'in s harfi. Daha güvenli fonksiyonlar.

-------

Etkisiz kod

En tehlikeli hatalardan biri, bir kodu yazarken yanlışlıkla niyetimizin dışında bir kod yazmak.
Ve kötüsü, bu niyetizimin dışında oluşan kod sentaks hatası değil.

Ifade geçerli, Deyim geçerli.

Elimizde bir ifade varsa, bu ifade geçerliyse, bu ifadenin sonuna ; tokenı koyulur ve geçerli bir deyim oluşur.
Bu şekilde oluşturulan deyime de ifade deyimi, expression statement denir. ->> expr;

5;          ->> Geçerli bir ifade, geçerli bir deyim
ival;       ->> Geçerli bir ifade, geçerli bir deyim
ival + 5;   ->> Geçerli bir ifade, geçerli bir deyim
ival == 5;  ->> Geçerli bir ifade, geçerli bir deyim

Derleyicilerin sık yaptığı lojik kontrollerde, eğer bir ifade deyiminde bir yan etki yoksa, 
yani bu deyim yürütüldükten sonra ne bir okuma işlemi yapılıyor ne bir yazma işlemi yapılıyor dışsal bir aygıta veya bir sürücüye,
ya da hiçbir değişkenin değeri değişmiyorsa, derleyici bu durumu şüpheyle karşılar ve uyarı mesajı verir.

Örnek Kod:

#include <stdio.h>

int main()
{
    int ival;
    printf("Bir sayi girin: ");
    scanf("%d", &ival);

    ival + 5; // ival += 5 yazmak yerine, bu şekilde yazdık.
} 

GCC Uyarı Mesajı

warning: statement with no effect

---------

Aşağıdaki kodda, foo isimli fonksiyon çağrıldığında programın return x + 1 ifadesine gelme şansı yok. Lojik hata.
Bu çok farklı biçimlerde de olabilir. If kontrol deyiminde veya döngü deyimlerinde.

#include <stdio.h>

int foo(int x)
{
    if (x > 10)
        return x * x;       //buraya girebilir
    else
        return x * x * x;   //buraya girebilir

    return x + 1;           //buraya girmez
}

Microsoft Derleyicisi Uyarı Mesajı

unreachable code

-----

unreachable code 2

int foo(void);

int func(int x)
{
    int x;

    for (;;) {
        x = foo();
        if (x % 2 == 0)
            return x;
    }

    return -1;
}

-----

stack overflow durumu - derleyicilerin bir kısmı bunu kontrol edebiliyor
bu genellikle recursive fonksiyonlarla ilgili. C ve C++'da bir fonksiyon kendi kodu içinde, yine kendisine çağrı yapıyor anlamına geliyor.
Kendi kendini çağıran fonksiyon.

int foo(int x)
{
    int y = x + 5;

    foo(y);
}

foo fonksiyonunu 5 ile çağırdım. y'nin değeri 10 oldu. 
foo fonksiyonunu 10 ile çağırdım. y'nin değeri 15 oldu.
foo fonksiyonunu 15 ile çağırdım. y'nin değeri 20 oldu.

Bu şekilde bir durum için stackoverflow terimi kullanılıyor. 
Stack, otomatik ömürlü değişkenlerin (yani fonksiyonun parametre değişkenleri, fonksiyonun içindeki yerel değişkenler) tutulduğu bellek alanında,
sürekli fonksiyon kendi kendisini çağırıyor. Durduracak hiçbir mekanizma yok, bu durumda stackde yer kalmıyor.

Çünkü fonksiyon sürekli kendisini çağırdıkça, yeni çağrılan fonksiyonun otomatik ömürlü değişkenleri de yine stack'de. İşte bu stackoverflow.

Derleyicilerin çoğu bu durumu, bu fonksiyonun sürekli kendisini çağırdığını ve stack'de taşmaya yol açacağını koda bakarak anlayabiliyor. 

int foo(int x)
{
    int y = x + 5;

    foo(y);

    return 1;
}

Microsoft Derleyicisi Uyarı Mesajı

'foo' recursive on all control paths, function will cause runtime stack overflow

Bu tür fonksiyonların stack overflow'a yol açmaması için belirli bir noktada artık kendisini çağırmaması gerekiyor.
Derleyici aşağıdaki koda bakarak burada bir base case'in bulunduğunu, yani belirli bir koşulda programın akışının oraya girip, sonlanacağını anlıyor.

int factorial(int x)
{
    if (x < 2)
        return 1;
    
    return x * factorial(x - 1);
}

---------

Örnek Recursive Fonksiyon - Faktoriyel hesaplama

int factorial(int x)
{
    if (x < 2)
        return 1;
    
    return x * factorial(x - 1);
}

Örnek Recursive Fonksiyon - Faktoriyel hesaplama - koşul operatörüyle

#include <stdio.h>

int factorial(int x)
{
    return x < 2 ? 1 : x * factorial(x - 1);
}

Örnek Recursive Fonksiyon - Fibonacci serisi hesaplama

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n < 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

---------

SORU: 

Her bir karşılaştırma işlemi 1 işlem. Arttırma da 1 işlem. Aranan değer veri yapısında olmadığı zaman, 3 * SIZE kadar işlem yapmış oluruz.

Kodu yeniden düzenleyerek 2 * SIZE kadar işlem yapılmasını sağlayabilir misiniz?

Test Kodu:

#include <stdio.h>
#include "dutility.h"

#define SIZE 100

int main()
{
    int a[SIZE];
    int sval;

    randomize();
    set_random_array(a, SIZE);
    print_array(a, SIZE);

    putline();

    printf("Aranan degeri giriniz: \n");
    scanf("%d", &sval);

    int i;

    for (i = 0; i < SIZE; ++i){
        if (a[i] == sval)
            break;
    }

    if (i == SIZE)
        printf("Aranan deger bulunamadi!");
    else
        printf("Aranan deger bulundu! Dizinin %d indisli elemani", i);
} 

Cevap:

Dizinin boyutunu bir arttırıyoruz, yani bir büyük oluşturuyoruz. a[SIZE + 1]
Fakat aranan değeri dizinin son öğesine yazıyoruz. a[SIZE] = sval;
Ardından döngüyü, a[i] != sval koşulunda yazıyoruz. Döngünün her turunda döngü değişkenimizi 1 arttırıyoruz.

Eğer aradığımız değer dizide varsa, bulunacak.
Ama aranan değer dizide yoksa, dizinin son öğesine yani SIZE indisli öğeisne aranan değeri yazdığımız için bu döngüden çıkacak.

Yalnızca 2 tane işlem var. Karşılaştırma ve Arttırma 

a[i] != sval

++i;

-----

#include <stdio.h>
#include "dutility.h"

#define SIZE 100

int main()
{
    int a[SIZE + 1];
    int sval;

    randomize();
    set_random_array(a, SIZE);
    print_array(a, SIZE);

    putline();

    printf("Aranan degeri giriniz: \n");
    scanf("%d", &sval);

    a[SIZE] = sval;

    int i = 0;

    while (a[i] != sval)
        ++i;

    if (i == SIZE)
        printf("Aranan deger bulunamadi!");
    else
        printf("Aranan deger bulundu! Dizinin %d indisli elemani", i);
} 

----

ÖDEV: Dizide, ilgili aranan sekansın ilk geçtiği yeri bulacağız. 
Bizim kodumuz çalıştığında, ya aranan sekans bulunamadı, ya da aranan sekans bulundu indeks = 6.
Ayrıca oluşturduğumuz algoritmanın karmaşıklığı nedir?

Örnek dizi elemanları ve aranan sekans:

Arama asagidaki dizide yapiliyor.

  1   2   4   0   4   4   3   3   2   4   0   0   1   2   1   1   0   2   2   1   1   4   2   3   2   2   1   1   3   0
  2   1   1   3   4   2   2   4   0   4   3   1   2   3   3   4   1   1   3   3   2   4   2   2   2   4   3   1   4   3
  1   0   0   2   3   1   0   2   4   3   1   0   0   4   0   0   1   1   3   3   4   3   4   4   1   0   1   1   1   3
  4   4   1   3   2   3   3   2   4   1

Aranan Sekans

  3   0   4

Test Kodu:

 #include <stdio.h>
 #include <stdlib.h>
 #include "dutility.h"
 #define SIZE           100
 #define SEQUENCE_SIZE  3

 int main()
 {
     int a[SIZE];
     int b[SEQUENCE_SIZE];

     for (int i = 0; i < SIZE; ++i) {
         a[i] = rand() % 5;
     }

     for (int i = 0; i < SEQUENCE_SIZE; ++i){
         b[i] = rand() % 5;
     }

     printf("\nArama asagidaki dizide yapiliyor.\n");
     print_array(a, SIZE);
     printf("\nAranan Sekans\n");
     print_array(b, SEQUENCE_SIZE);
 }

------

ÖDEV:

#include <stdio.h>
 #include "dutility.h"
 #define SIZE   10

 int main()
 {
     int a[SIZE + 1];
     //bu dizide 0 dahil SIZE - 1 hariç tüm sayılardan birer tane var.
     //ancak bir sayıdan iki tane var.
     //aynı iki tane elemanı bulmamız gerekiyor.
     //dizinin elemanları 0 ile SIZE arasında.
 }
 
------

Kod tekrarı felakettir. 

Eğer bir kod birden fazla yerde tekrar ediliyorsa, orada lojik bir değişiklik yapmak gerektiğinde, değişikliği birden fazla yerde yapmamız gerekir.

Aynı kod birden fazla yere yazıldığında, codesize büyüyebilir. Bundan dolayı çalıştırabilir kod da büyümüş olabilir. Özellikle embedded tarafta bir darboğaz oluşabilir.

------

POINTERS

Bundan öncesinde, Neslerin değerlerini kullandık, değerleri değişkenlerde sakladık, fonksiyonlara değişkenlerimizin değerlerini gönderdik, 
fonksiyonlardan geri dönüş değeri olarak tam sayı gerçek sayı gibi değerler aldık, dizilerin elemanlarında tam sayı gerçek sayı gibi değerler tuttuk.

Fakat C dili büyük ölçüde adres kavramını kullanan bir dil. 

Değişkenlerde nesnelerin adreslerini tutacağız, fonksiyonlara nesnelerin adreslerini göndereceğiz, dizimizin elemanları adresler tutacak, fonksiyonların geri dönüş değeri adres olacak.

C dili bu açıdan baktığımızda diğer programlama dillerinden farklı. Adres donanımsal bir kavram olmasına rağmen, C dilinde yazılımsal olarak da kullanılabilen bir kavram. 

Çünkü C dili daha düşük seviyeli bir dil. Orta seviyeli dillerin alt kesimi. Daha çok sistem programlama tarafında kullanıldığından C'nin genel sentaksı ve araçları makinada olan bitenleri daha iyi betimlemeye yönelik.

Yani normalde eğer adres kavramı, programlama dilinin kavramlarından biriyse, kod yazma - soyutlama yapma zorlaşıyor. Yüksek seviyeli dillerde donanımsal olarak bir adres kavramı var fakat bu bizden izole edilmiştir.

Ama C dilinde, bir çok işi yapabilmek için dil katmanında da adresleri kullanmamız gerekiyor. İşte C ve C++ gibi dillerde pointer sözcüğü tamamen adres anlamında kullanılan bir sözcük.

pointer ->>> address

Nasıl bizim adresimiz varsa, Doğukan Yazar'ın adresi, nerede yaşadığı - oturduğu bilgisi varsa, nesnelerin adresleri de programın çalışma zamanında nesnelerin bellekte nerede olduğunu anlatan bir bilgi.

Yani bir nesnenin adresi demek, o nesne bellekte nerede sorusunun cevabı. Dolayısıyla bir nesnenin adresinden bahsettiğimizde veya bir nesnenin adresini kullandığımızda, aslında kullandığımız programın çalışma zamanında o nesnenin bellekte yeri.


C ve C++ dili adres kavramını öncelikle ikiye ayırıyor. 

1) Nesne Adresleri      (Object Pointers)   ->> Değişkenlerimizin adresleri
2) Fonksiyon Adresleri  (Function Pointers) ->> Fonksiyonlarımızın adresleri

Madem bu dilde değişkenlerin adresleri dil tarafında kullanılan bir bilgi. O zaman bu dillerin kurallarına göre bazı ifadeler adres anlamına gelecek.

int ival = 10;

ival        -> ifadenin türü: int
ival + 0.2  -> ifadenin türü: double

Her ifadenin bir türü var. Adres de dil içerisinde kullanılan bir kavram olduğuna göre, bazı ifadelerin değeri adres anlamına gelecek. 
Bu durumda da dilin kuralları, değeri adres olan ifadelerin de bir türünün olmasını gerektiriyor.

İşte şimdi burada C ve C++ dillerinin bir aksiyomu devreye giriyor.

Dilin tasarımını kabul etmemiz gerekiyor.

Eğer x türü T olan bir değişken ise

bir ifade

    x değişkeninin adresi anlamına geliyor ise

    o ifadenin türünün C'de gösterimi: T * 

Yani int türü var ise, int * türü de var. 

int türden bir değişkenin adresi olan ifadenin türü int *.
double türden bir değişkenin adresi olan ifadenin türü double *.
char türden bir değişkenin adresi olan ifadenin türü char *.

Bu durumda şimdiye kadar kaç tane türümüz var, onu 2 ile çarpmalıyız. Yani her tür için bir de adres türümüz var.

-----

    int x = 10;

    &x //bu ifadenin türü, int * türü.

Adres operatörünün operandı bir nesne bir değişken olduğunda bu ifadenin o değişkenin adresi anlamına geliyor.
Bu ifadenin türü, x'in türü int olduğuna göre, bu ifade de x'in adresi anlamına geldiğine göre bu ifadenin türü ise int *

    double x = 10;

    //double * 

-----

Şimdiye kadar değişkenlerimiz tam sayı ya da gerçek sayı değerlerini tutuyordu. Ama bundan sonra kullanacağımız ayrı bir değişken kategorisi var. Bunların varlık nedeni değişkenlerin adreslerini tutmak.

int türünden x'in değerini sorduğumuzda, değer 10 olabilir 20 olabilir herhangi bir değer olabilir.
Ama aynı soruyu pointer değişkenlere sorduğumuzda, değer x'in adresi. 

Yani pointer değişkenler, değeri adres olan değişkenler.

    int* ptr;
    //ptr değişkeninin türü int *
    //ptr değişkeni int türden değişkenlerin adreslerini tutmak için var.
    //ptr'nin değeri int türden bir değişkenin adresi.

----

İki farklı değişken kategorimiz var.

Değeri tam sayı, gerçek sayı olan değişkenler
Değeri başka değişkenlerin adresleri olan değişkenler

int * ptr -> bunlar ayrı tokenlar oldukları için bitişik yazılması veya arada boşluk olması bildirimin anlamını değiştirmiyor.

Fakat yaygın iki ayrı tarz var.

Birincisi asterisk atomunu bildirimde tür belirten anahtar sözcüğe bitişik yazmak.
İkincisi asterisk atomunu bildirimde pointer değişkenin ismi olan isme bitişik yazmak.

int* ptr;
int *ptr;

a) İlk değer vermeden tanımlayabiliriz.
b) İlk değer verebilirim.

Bunlar adres tutan değişkenler olacağı için, bunlara ilk değer verdiğimizde veya atama yaptığımızda, kullanılan ifadenin adres bilgisi olması gerekir.

----

İngilizcede böyle bir değişkenin türü, pointer to int şeklinde söyleniyor. 
Eğer pointer değişkenimiz, int türden bir nesnenin adresini saklamak için varsa, bunu betimlemek için pointer to int kullanılıyor.

int* ptr;
//pointer to int

double* ptr;
//pointer to double

Pointer değişkenlerin ait olduğu adres türleri, değerlerin nesne adresi olan değişkenler, bellekte aynı miktarda yer kaplıyorlar.

int*
char*
double*

Yukarıdaki türden değişkenler bellekte aynı miktarda yer kaplayacaklar. Bu çok önemli bir nokta. Tabi bu sistemden sisteme, derleyiciden derleyiciye göre değişebilir.
Ama bir sistemde bir derleyicide pointer türü 4 byte ise, bu türler 4 byte yer kaplayacaktır.

#include <stdio.h>

int main()
{
    printf("sizeof(char)        = %zu\n", sizeof(char));
    printf("sizeof(short)       = %zu\n", sizeof(short));
    printf("sizeof(int)         = %zu\n", sizeof(int));
    printf("sizeof(double)      = %zu\n", sizeof(double));
    printf("sizeof(char *)      = %zu\n", sizeof(char *));
    printf("sizeof(short *)     = %zu\n", sizeof(short *));
    printf("sizeof(int *)       = %zu\n", sizeof(int *));
    printf("sizeof(double *)    = %zu\n", sizeof(double *));
}

Tıpkı diğer değişkenlerde olduğu gibi, değeri adres olan pointer değişkenlerimiz;

global alanda veya yerel alanda değişken olabilir, 
otomatik veya statik ömürlü yerel değişken olabilir, 
fonksiyonların parametre değişkenleri olabilir.

#include <stdio.h>

int* gp;            //global kod alanındaki pointer değişkeni

void func(void)
{
    int* px;        //otomatik ömürlü yerel bir pointer değişkeni
    static int* py; //statik ömürlü yerel bir pointer değişkeni
}

void foo(int* ptr)  //fonksiyonun parametre pointer değişkeni
{

}

*/