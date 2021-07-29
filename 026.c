/*

POINTERS

Pointer için Türkçe terim olarak gösterici veya işaretçi sözcükleri kullanılabilir.

int *ptr; // ptr is a pointer to int

int* p1, p2;

int* p1;
int p2;

Dilin tasarımını yapanlar bu deklaratörlerin (*) sadece önüne ya da arkasına geldikleri isimleri nitelemesi biçiminde bu kuralı seçmişler.
Yani yukarıdaki virgüllerle ayrılan listedeki hem p1'i hem p2'i değil, sadece p1'i niteliyor.

int x, *p, a[10], *q;

Buradaki int anahtar sözcüğü bildirimdeki isimlerin tamamını niteliyor.

Fakat buradaki * önüne geldiği p ismini, köşeli parantez arkasına geldiği a ismini niteliyor.

int x;

int *p;

int a[10];

int *q;

------

int *p1, *p2;

------

Pointer değişkenlerin varlık nedeni adres tutmak olan değişkenler. 
Dolayısıyla diğer tüm değişkenlerde olduğu gibi pointer değişkenimizin mantıklı, tutarlı bir değere sahip olması için ya ona ilk değer vereceğiz, ya da ona bir atama yapacağız.
Bu açıdan baktığımızda diğer değişkenlerle pointer değişkenlerin bir farkı yok.

Sadece fark, ilk değer verdiğimiz ifade bir adres anlamına gelmeli, atama yaptığımızda da atama operatörünün sağ tarafı olan ifade bir adres olmalı.

Diğer değişkenlerde olduğu gibi eğer otomatik ömürlü bir pointer değişkeni oluşturursak bu değişken hayata çöp değerle başlar.
Garbage Value, Indetermined Value

Böyle bir değişkeni, ona değer atamadan kullanırsak, bütün değişkenlerde olduğu gibi tanımsız davranıştır.

Eğer statik ömürlü bir değikenimiz olsaydı, ona ilk değer vermediğimizde hayata 0 değeriyle başlayacaktı.
Ama pointer değişkenlerin özel bir değeri var, null pointer.
Statik ömürlü bir pointer değişkene ilk değer vermediğimizde, null pointer değerine sahip oluyor.

Bir pointer değişkenin varlık nedeni adres tutmak olduğu için ona adres atamamız ya da bir adresi ilk değer vermemiz gerekiyor.

Pointerlarla ilgili bir çok işlemin yapılabilmesi için C dilinin bazı operatörlerini bilmemiz gerekiyor.

Bu operatörlerin oluşturduğu gruba pointer operatörleri denir.

--------------------------

&   Address of operator (Adres operatörü)

Operatör öncelik tablosunda 2. öncelik seviyesinde
Sağdan sola öncelik yönü
--------------------------

*   Dereferencing / Indirection Operator (İçerik operatörü)

Operatör öncelik tablosunda 2. öncelik seviyesinde
Sağdan sola öncelik yönü
--------------------------

[ ] Subscript / Index Operator (Indeks operatörü - Köşeli parantez operatörü)

Operatör öncelik tablosunda 1. öncelik seviyesinde
Soldan sağa öncelik yönü
--------------------------

-> Member Selection / Arrow operator (Ok operatörü)

Operatör öncelik tablosunda 1. öncelik seviyesinde
Soldan sağa öncelik yönü
--------------------------


Adres Operatörü

Bu operatörün tokenı &.
Unary olarak kullanıldığında adres operatörü
Binary olarak kullanıldığında "bitwise and" yani "bitsel ve operatörü" şeklinde kullanılıyor.

Unary prefix - Ön ek konumunda - Tek operand alan
Bu operatörün operandın L value expression yani sol taraf değeri olmak zorundadır.

Adres operatörünün ürettiği değer operandı olan nesnenin adresi.

&x demek, x değişkeninin adresi demek.

----------------

int x = 10;

&x ifadesinin türü nedir? 
int türden bir değişkenin adresi olan ifadenin türü int *.

----------------

int *ptr;
*ptr ifadesinin türü nedir?
int *

----------------

Bir pointer değişkene atanabilecek ya da ilk değer verilebilecek ifadeyi adres operatörüyle elde edilmiş bir nesnenin adresi.

    int x = 10;
    int *ptr = &x;

Türü int * olan ismi ptr olan bir değişken tanımladık. 
Bu değişkene x'in adresiyle ilk değer verdik.

----------------
    int x = 10;
    int y = 20;
    
    int *ptr = &x;  //ilk değer verme
    ptr = &y;       //atama

----------------

Eğer bir pointer değişkenin değeri, bir değişkenin adresiyse, bunu ifade etmenin C ve C++ dillerinden birden fazla yolu var.

ptr'nin değeri x'in adresi söylemini aşağıdaki gibi ifade edebiliriz.

ptr points to x = ptr x'i gösteriyor

int main()
{
    int x = 10;
    int y = 20;
    
    int *ptr = &x;
    //ptr x'i gösteriyor

    ptr = &y;
    //ptr y'yi gösteriyor
}

----------------

Tanımladığımız pointer değişken p ama p'ye ptr'nin değeriyle ilk değer veriyoruz.
Bu durumda p ile ptr'nin değeri aynı. İkisinin de değeri x'in adresi.

int main()
{
    int x = 10;
    int y = 20;

    int *ptr = &x;
    int *p = ptr;

    //p'yi hayata ptr'nin değeri olan adres ile hayata başlatıyoruz. yani x'in adresi.
}

----------------

Bildirimler, virgüllerle ayrılan listede başlangıçta karışık gelebilir.

Virgüllerle Ayrılan Liste

    int x = 10, *p1 = &x, *p2 = p1;

Liste Olmadan Bildirim

    int x = 10;
    int *p1 = &x;
    int *p2 = p1;

-------------------------

Adres operatörüyle oluşturulmuş ifadeler sağ taraf değeridir. R value expression
Böyle ifadelerin atama operatörünün sol operandı olamazlar.

C ve C++ dillerinde hayata gelmiş nesnelerin adreslerinin değişmesi gibi bir kavram yok. Ne de böyle bir araç var.

Bir nesne bir adreste bir bellek bloğunda hayata gelir, hayatı bitene kadar o bellek bloğundadır.
Hayatı devam ederken bellekte bir yerden başka bir yere taşınması gibi bir şey söz konusu değil.

Bir değişkenin adresini değiştiremeyiz. Ama bir pointer değişkenin değerini değiştirebiliriz.

    int x, y, z;
    int *ptr;

    ptr = &x;
    //code
    ptr = &y;
    //code
    ptr = &z;

-------------------------

Aşağıdaki kod legal midir?

& &x;

Legal değildir. Sentaks hatasıdır. Öncelik yönü sağdan sola. Adres operatörünün operandı sol taraf değeri olmak zorundadır.

-------------------------

Bir nesnenin adresinin adresi diye bir şey yok.
Fakat bir pointer değişkenin kendi adresi vardır.

&ptr = ptr bellekte nerede

-------------------------

printf fonksiyonunun %p formatlama dönüştürücüsü ile pointer değişkenlerini yazdırabiliriz.

    int x = 10;
    int *ptr = &x;

    printf("&x = %p\n", &x);

-------------------------

Mikroişlemcilerde adresler söz konusu olduğunda geleneksek olarak adreslere ilişkin tam sayı değerlerini 16'lık sayı sisteminde ifade ediliyor.
C dilinde de bu geleneği uyulmuş. %p ile bir adres bilgisini standart output'a yazdırdığımızda sayı sistemi olarak 16'lık sayı sistemi kullanılıyor.

#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr = &x;

    printf("&x = %p\n", &x);
    printf("ptr = %p\n", ptr);
    printf("&ptr = %p\n", &ptr);
}

-------

2 byte'lık bir pointer 0 ile 65535 arasındaki tam sayı değerleri tutabilir.
2 byte'lık bir pointer ile 64KB'lık bir bellek bloğundaki nesnelerin adreslerini tutabilirsiniz.

4 byte'lık bir pointer olduğunda, çok daha büyük bir bellek bloğundaki nesnelerin adreslerini tutabiliriz.

-------

Bir dizinin ismi bir ifade içerisinde kullanıldığında iki istisna dışında derleyici tarafından dizinin ilk elemanının adresine dönüştürülüyor.

Bu kurala array decay denir. (array to pointer conversion)

int main()
{
    int a[10] = { 0 };

    printf("&a[0] = %p\n", &a[0]);
    printf("a = %p\n", a);
}

-------

Array decay'in uygulanmadığı yerlerden biri sizeof operatörünün operandının bir dizi ismi olması

#include <stdio.h>

int main()
{
    int a[10] = { 0 };

    printf("sizeof(a)     = %zu\n", sizeof(a));         //dizinin kaç byte yer kapladığı
    printf("sizeof(&a[0]) = %zu\n", sizeof(&a[0]));     //dizinin ilk elemanının kaç byte yer kapladığı
}

-------

Dizinin adresi = Dizinin ilk elemanının adresi

    int a[10] = { 0 };
    int *p1 = &a[0];
    int *p2 = a;

-------

1 - Adres operatörüyle oluşturulan bir ifadeyi bir pointer değişkenine ilk değer verebiliriz veya atama yapabiliriz.

    int x = 10;
    int *p = &x;

2 - Bir başka pointer değişkenin değeriyle bir pointer değişkenine ilk değer verebiliriz veya atama yapabiliriz.
    
    int x = 10;
    int *p = &x;
    int *q = p;

3 - Bir pointer değişkene dizinin ismi biçiminde yazılmış dizinin ilk elemanının adresiyle ilk değer verebiliriz veya atama yapabiliriz.

    int a[10] = { 0 };
    int *p = a;

-------

    int x = 10, *p = &x, a[] = {1, 3, 5}, *q = a;

    int x = 10;
    int *p = &x;
    int a[] = {1, 3, 5};
    int *q = a;

-------

Asla böyle bir kod yazmamalıyız.

    int x = 10;
    int * ptr;

    ptr = x;

Atama operatörünün solundaki nesnenin türü int *
Atama operatörünün sağındaki nesnenin türü int

int * türünden bir nesneye int türünden bir değer atıyoruz.
C dilinin kurallarına göre int türünden int * türüne otomatik dönüşüm var.

Biz x'in değerini atamamıza rağmen, derleyici bunu bir adrese dönüştürüyor.
Aslında x'in adresini değil, x'in değeri olan 10 adresini ptr'ye atamış oluyoruz.

Bir pointer değişkene adresi olmayan bir veriyle ilk değer verdiğimizde ya da atama yaptığımızda,
bu bir sentaks hatası değil fakat derleyicilerin hepsi bunun yanlış olduğunu ifade eden bir uyarı mesajı verecektir.

GCC Uyarı Mesajı

warning: assignment makes pointer from integer without a cast

C++ dilinde bu durum sentaksı.

C dilinde aritmetik türlerden adres türlerine otomatik dönüşüm varken C++ bu konuda çok katı. C++'da doğrudan sentaks hatası.

-------

Asla böyle bir kod yazmamalıyız.

    double x = 1.20;
    int* ptr;

    ptr = &x;

Atama operatörünün solundaki nesnenin türü int *
Atama operatörünün sağındaki nesnenin türü double *

int * türünden bir nesneye double * türünden bir değer atıyoruz.
C dilinin kurallarına göre double * türünden int * türüne otomatik dönüşüm var.

GCC Uyarı Mesajı

warning: assignment from incompatible pointer type

C++ dilinde bu durum sentaksı.

------

C dilinde doğrusu, iyisi;

1) Bir pointer değişkene sadece adres atamak. Asla ve asla bir tam sayı veya gerçek sayı değeri atamamak.
2) Bir pointer değişkene onun tutmaya aday olduğu bir türden nesnenin adresini ilk değer vermek veya adresini atamak.

Bu durumları C derleyicileri sentaks hatası olarak değil, lojik uyarı mesajları olarak vereceklerdir.

-------------------------

İçerik operatörü
Dereferencing / indirection operator

Asterisk (*) atomu binary olarak kullanıldığında çarpma operatörü, unary olarak kullanıldığında içerik operatörü.

Operatör öncelik tablosunda 2. öncelik seviyesinde
Sağdan sola öncelik yönü

Unary prefix bir operatör. Aynı adres operatöründe olduğu gibi.

*operand

İçerik operatörünün operandı adres ifadesi olmak zorundadır.
Derleyici bunu compile time'da kontrol ediyor.

int main()
{
    int x = 10;
    int *ptr = &x;
    int a[] = {1, 2, 3, 4};

    // *234;    geçersiz
    // *x;      geçersiz
    // *&x;     geçerli
    // *ptr;    geçerli
    // *a;      geçerli - geçerli olmasını sağlayan array decay
}

------

İçerik operatörüyle oluşturulmuş bir ifade, bizi operand olan adresteki nesneye eriştirecek.

Yani *adres demek, bu adresteki nesne demek.

Bir adresteki nesneye erişmek için tek yapmamız gereken o adres ifadesini içerik operatörünün operandı yapmak.

*adres -> eğer bu adres, x değişkenin adresiyse, bu ifade x değişkeninin kendisi
*adres -> eğer bu adres, ival değişkenin adresiyse, bu ifade ival değişkeninin kendisi

------

    int x = 10;
    
    *&x = 45;

Çünkü sağdan sola öncelik yönü olduğuna göre, içerik operatörünün operandı x'in adresi.
İçerik operatörü de bu nesneye eriştirdiğine göre, biz bu atamayı x'e yapmış oluyoruz.

------

int main()
{
    int x = 10;
    ++*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&x;
    //++x - yazmakla hiçbir farkı yok. tabiki böyle bir kod yazmamalıyız.
    
    printf("%d", x);
}

------

    int a[] = {7, 23, 56};

    *a = 44;

Derleyici koda bakayarak önce array to pointer conversion uyguladı, yani array decay.
Dolayısıyla *a demek a[0] anlamına geliyor. a'nın ilk elemanının değeri 44 oldu.

------

    int x = 10;
    int *p = &x;

    *p = 98;

p, x'in adresini ilk değer almış bir pointer değişken.
İçerik operatörünün operandı p ifadesi olduğuna göre, p'nin değeri x'in adresi.
O adresteki nesneye eriştiğimize göre, *p demek, p'nin gösterdiği nesne demek.

*p demek x demek. x = 98

------

T *ptr = &x;

T bir tür olmak üzere, eğer *ptr T türünden bir pointersa ve bir nesneyi gösteriyorsa

*ptr demek ptr'nin gösterdiği nesne demek.

pointer - point eden, gösteren
pointee - point edilen, gösterilen 

------

Bir pointer değişken bir nesneyi gösteriyorsa, 
biz o değişkenin ismini yazmadan pointer değişkeni vasıtasıyla onun adresini tuttuğu nesneye erişebiliyoruz.

Bir adres üzerinden bir nesneye erişme işlemine indirection ya da dereferencing deniyor.

------

#include <stdio.h>

int main()
{
    int x = 10, y = 20, z = 30;
    int *p;

    p = &x;
            *p = 44; //atama x değişkenine yapılıyor
    p = &y;
            *p = 44; //atama y değişkenine yapılıyor
    p = &z;
            *p = 44; //atama z değişkenine yapılıyor

    printf("x = %d y = %d z = %d\n", x, y, z);
}

------

Eğer atama operatörünün sol tarafındaki pointer değişkense, sağ taraftaki ifadenin bir adres olması gerekiyor.
Bu pointer değişkenin değerini değiştirmek.

p = &y; 

Eğer atama operatörünün sol operandı *p ise, burada p'nin değerini değiştirmiyoruz. p'nin gösterdiği nesnenin değerini değiştiriyoruz.

*p = 10;

------

#include <stdio.h>

int main()
{
    int x = 10, *p1 = &x, *p2 = p1, *p3 = p2;

    ++* p1; //11
    ++* p2; //12
    ++* p3; //13

    printf("x = %d\n", x);
}

------

Programlama dillerinde bir fonksiyona yapılan çağrı popüler olarak call by value veya call by reference şeklinde isimlendiriliyor.

call by value - değerle çağrı
bir fonksiyona bir nesnenin değerini göndermek

call by reference - nesneyle çağrı
bir fonksiyona bir nesnenin kendisini göndermek

----

#include <stdio.h>

void func(int a)
{
    a = 23;
}

int main()
{
    int x = 10;

    func(x);
}

----

C dilinden bağımsız olarak, bu fonksiyon çağrısından sonra x değişkeninin değeri halen 10 mu yoksa 23 mü?
Eğer bu fonksiyon çağrısı call by value ise halen 10, call by reference ise 23.

C dilinde bütün fonksiyon çağrıları call by value. 
Yani bu fonksiyon çağrıldığınd hayata gelen parametre değişkeni ayrı bir değişken, x ayrı bir değişken.
a demek x demek değil.

a ve x değişkenlerinin adreslerini yazdırarak a ve x'in aynı değişken olmadığını anlayabiliriz.

Fonksiyonun parametre değişkeni olan "a" ayrı bir değişken, "x" ayrı bir değişken. call by value. 

Buradaki atama fonksiyonun parametre değişkenine yapılıyor. x değişkeninin değeri değişmiyor.

----

#include <stdio.h>

void func(int a)
{
    printf("&a = %p\n", &a);
    a = 23;
}

int main()
{
    int x = 10;
    printf("&x = %p\n", &x);

    func(x);
}

----

C dilinde eğer bir fonksiyonun yerel değişkenin bir fonksiyon tarafından değiştirilmesini istiyorsak, fonksiyona bir nesnenin kendisini göndermek gerekiyor.
C dilinde call by reference, yani bir fonksiyona nesnenin kendisinin gönderilmesi pointer semantiğiyle gerçekleşiyor.

C'nin sentaksı makinade olan biteni daha iyi betimlemeye yönelik.
Çünkü bir fonksiyon başka bir fonksiyonun yerel değişkenine ancak o değişkenin adresi yoluyla erişebilir.

Bunu C'de yapmanın yolu fonksiyonun parametre değişkenini bir pointer yapmak ve bu fonksiyonu bir adresle çağırmak.
O zaman biz bu fonksiyona x'in adresini argüman olarak gönderdiğimde, bu fonksiyon çağrıldığında parametre değişkeni x'i gösteriyor olacak.

Fonksiyonun ana bloğu içinde *ptr, bu fonksiyona hangi nesnenin adresini gönderilmişse, o nesne olacak.

C dilinde call by reference ile çağrı yapmanın yolu bir fonksiyona bir nesnenin adresini göndermek.
Başka bir yolu yok.

----

#include <stdio.h>

void func(int *ptr)
{
    *ptr = 1000;
}

int main()
{
    int x = 10;

    func(&x);

    printf("x = %d\n", x);
}

----

Takas kodu

#include <stdio.h>

int main()
{
    int x, y;
    printf("Iki tam sayi girin: ");
    scanf("%d%d", &x, &y);

    printf("x = %d y = %d\n", x, y);
    int temp = x;
    x = y;
    y = temp;

    printf("x = %d y = %d\n", x, y);
}

----

Takas kodunu bir fonksiyon haline getirmek

#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int x, y;
    printf("Iki tam sayi girin: ");
    scanf("%d%d", &x, &y);

    printf("x = %d y = %d\n", x, y);

    swap(&x, &y);

    printf("x = %d y = %d\n", x, y);
}

----

#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {2, 4, 6, 8};

    swap(a, b);

    printf("a[0] = %d b[0] = %d\n", a[0], b[0]);
}

----

#include <stdio.h>

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int x = 45, y = 56, *p1 = &x, *p2 = &y;

    swap(p1, p2);

    printf("x = %d y = %d\n", x, y);
}

----

Neden call by reference yapıyoruz?

Öyle durumlar var ki, bizim çağırdığımız fonksiyonun bizim nesnemizin değerini değiştirmesi gerekiyor.
Yukarıda yazdığımız swap fonksiyonu gibi veya scanf fonksiyonu gibi.

Çünkü scanf bizim gönderdiğimiz değişkeni, standart input'dan gelen karakterlerle set ediyor.
Bunu yapabilmesi için nesnenin kendine erişmesi gerekiyor.

Call by reference, çünkü bir fonksiyonun bir nesneyi set etmesinin başka bir yolu yok.

--------

İlkel bir scanf fonksiyonu

#include <stdio.h>

void scan_int(int *ptr)
{
    int c;
    *ptr = 0;

    while ((c = getchar()) != '\n'){
        *ptr = *ptr * 10 + c - '0';
    }
}

int main()
{
    int x;
    printf("Bir tam sayi girin: ");
    scan_int(&x);

    printf("x = %d\n", x);
}

--------

Bir fonksiyonun call by reference biçiminde yazılmasının en tipik nedeni şu:

Fonksiyon kendisini çağıran fonksiyona bir değer iletmek istiyor. 
Bunu yapmanın şimdiye kadar olan yolu geri dönüş mekanizmasını kullanmaktı.

Şimdiye kadar bir değer hesaplamaya yönelik fonksiyonları hep geri dönüş mekanizmasıyla yaptık.
Fonksiyonun geri dönüş değeri hesaplanan değer oldu.

Şimdi hesaplanan değer, geri dönüş değeri ile değil de, veri aktarımını fonksiyona gönderilen adresteki nesneye yazmakla gerçekleşiyor.

--------

Dairenin alanını hesaplayan fonksiyon - call by value - geri dönüş mekanizmasıyla

#include <stdio.h>

double get_circle_area(double radius)
{
    return 3.14159268 * radius * radius;
}

int main()
{
    double r = 23.75254;
    double area;

    area = get_circle_area(r);

    printf("area = %.4f", area);
}

--------

Dairenin alanını hesaplayan fonksiyon - call by reference - nesnenin kendisini kullanmak

#include <stdio.h>

double get_circle_area(double radius, double *p_area)
{
    *p_area = 3.14159268 * radius * radius;
}

int main()
{
    double r = 23.75254;
    double area;

    get_circle_area(r, &area);

    printf("area = %.4f\n", area);
}

--------

call by value vs call by reference

Eğer hesaplanacak değer bir tam sayı, bir gerçek sayı ise, call by reference biçimini kullanmak fazladan bir fayda sağlamadığı gibi görüntüyü biraz daha karmaşık hâle getirebilir.
call by reference biçiminde hesaplanacak değeri tutacak bir değişken ihtiyacımız var. Onun adresini göndereceğiz ki, hesaplanacak değeri o adresteki nesneye yazsın.

call by value yönteminde hesaplanacak değeri herhangi bir değişkende saklamadan, doğrudan değer olarak kullanabiliriz.

Dolayısıyla buradaki tercihimiz call by value.

!!AMA!!

Eğer hesaplanacak değer bellekte int türü, double türü gibi 4 byte 8 byte değil de, 40 byte 50 byte yer kaplıyorsa, 
1. yöntem ve 2. yöntem arasında ciddi bir maliyet farkı olacak.

Fonksiyonlar geri dönüş değerlerini ürettiği zaman derleyici şöyle bir kod üretiyor.

T bir tür olsun. Herhangi bir tür.

T func(****);   //fonksiyon tanımladık

T x;            //fonksiyon geri dönüş değerini tutmak için bir değişken tanımladık

x = func();     //hesaplanan değerin x'e aktarılması

Assembly seviyesinde bu kod karşılığı üretilen kod aslında şöyle, 
func'ın geri dönüş değeri biz görmesek de geçici bir nesnede tutuluyor, temporary object.
Yani kodda ismi yok ama çalışan kodda kullanılan bir bellek alanı var.

func fonksiyonu hesapladığı değeri bu geçici nesneye yazıyor, biz de bu geçici nesneden kendi değişkenimize aktarıyoruz. x = func();
bu aktarım tamamlandıktan sonra bu geçici nesnenin de ömrü bitiyor.

Dolayısıyla burada iki tane bellek bloğu kopyalaması var.

Birincisi, return ifadesinin değerinin bu fonksiyonun geri dönüş değerini aktarmada aracılık yapacak geçici nesneye yazılması.
Ikincisi, fonksiyonu çağıran kodun, fonksiyonun geri dönüş değerini kendi değişkenine aktarması.

Eğer aktarılacak değer 4 byte, 8 byte gibiyse bu işlem ilave bir maliyet getirmiyor.
Ama bizim değerlerimiz 4 byte veya 8 byte ile sınırlı değil. Ileride user-defined types denilen kendi türlerimizi kullanacağız.
Bir nesnenin bellekte kapladığı yer örneği 40 byte veya 100 byte olabilecek.

----

Aşağıdaki türden bir nesne bellekte 1608 byte yer kaplıyor.

#include <stdio.h>

typedef struct {
    int wor, col;
    int a[20][20];
}Matrix;

int main()
{
    printf("sizeof(Matrix) = %zu\n", sizeof(Matrix));
}

----

Fonksiyonumuzun ürettiği değer yani çağıran koda ilettiği değer, bir tam sayı veya gerçek sayı olmak yerine bir matris olsaydı.
Geri dönüş değeri Matrix türü olan bir fonksiyon ve biz bu fonksiyonun geri dönüş değerini bir değişkende saklamak isteseydik.

#include <stdio.h>

typedef struct {
    int wor, col;
    int a[20][20];
}Matrix;

Matrix func(void)
{
    Matrix m;

    ////code

    return m;
}

int main()
{
    Matrix mymatrix;

    mymatrix = func();
}

Fonksiyonumuz çağrıldığında muhtemelen fonksiyon tanımında yerel bir değişken olacak.
Fonksiyon da yaptığı hesaplamanın sonucunda return m diyecek.

Derleyicinin ürettiği kodda fonksiyonun geri dönüş değeri geçici nesneye aktarılacak.
1608 byte'lık bir kopyalama olacak. Buradan da bizim nesnemize bir kopyalama olacak. 

Yani fonksiyonun hesapladığı matrisi çağıran koda iletmesi 2 kez 1068 byte'lık bloğun kopyalanmasıyla oldu.
En yüksek maliyet büyük bellek bloklarının kopyalanması.

Peki bunun alternatifi nedir?

Fonksiyonun kodunu böyle yazmak yerine, parametresini bir pointer yapmak ve bu fonksiyonu bizim matris nesnemizin adresiyle çağırmak.

Bir pointer değişkeni sisteme ve derleyiciye göre 4 veya 8 byte olabilir.

İki kez 1608 byte'lık bellek bloğunun kopyalanması yerine, sadece 4 byte'lık bir adresi kopyaladık. 
Bu ciddi bir maliyet farkı demek. 

----

#include <stdio.h>

typedef struct {
    int wor, col;
    int a[20][20];
}Matrix;

void func(Matrix *p)
{
    Matrix m;

    ////code

    return m;
}

int main()
{
    Matrix mymatrix;

    func(&mymatrix);
}

----

Öyle fonksiyonlar var ki, bu fonksiyonlar yaptıkları iş gereği bir tam sayı ve gerçek sayı hesaplamıyorlar.
user-define types türlerden değer hesaplıyorlar. Bu hesaplanan değer için 50 byte 100 byte 500 byte bir bellek bloğu gerekebiliyor.

Bu durumda biz klasik modelle bu fonksiyonu yazdığımızda, yani fonksiyonun geri dönüş değeri mekanizmasıyla fonksiyon hesapladığı değeri aktardığında, 
blok kopyalamasından dolayı ciddi bir maliyet oluyor.

Bu tür fonksiyonları C'de yazarken herkes maliyeti düşürmek için bu değerin aktarılmasında geri dönüş değeri mekanizması değil de,
fonksiyonu çağıran kod, bizim hesaplayacağımız değeri tutacak nesnenin adresini göndersin, 
bizim fonksiyonumuzda o adrese hesapladığı değeri yazsın.

Böylece iki yapı arasındaki maliyet farkı çok çok büyük olabilir.

Bir de bu fonksiyonun döngüsel bir yapı içerisinde yüzlerce, binlerce kez çağrıldığında düşünürsek,
geri dönüş değeriyle aktarım buna göre son derece ağır kalacak.

----

Eğer bir fonksiyon bir değer hesaplıyorsa ve hesapladığı değer int gibi double gibi 4 byte, 8 byte veya 12 byte'lık gibi bellek bloklarında tutulacak bir değerse,
fonksiyonun geri dönüş değerini tür yapmaya çekinmemeliyiz. Bunun çok ciddi bir maliyeti olmaz.

Ama eğer fonksiyonun hesapladığı değer daha büyük bir bellek bloğunda tutuluyorsa, 40 byte 50 byte veya 100 byte gibi, o zaman artık geri dönüş mekanizmasını kullanmak programımızı bir hayli yavaşlatabilecek.

Senaryolardan biri - Maliyeti düşürmek

----

Gerçek hayatta bir çok durumda fonksiyonlar birden fazla değeri hesaplayıp kendilerini çağıran koda iletmek zorundadırlar.
Yani fonksiyonun varlık nedeni örneğin 3 tane ayrı değer iletmek. Bir fonksiyonun bir tane geri dönüş değeri olur. Geri dönüş değeri mekanizmasıyla birden fazla değeri çağıran koda iletmesi mümkün değil.

Mühendislikle ilgili bir hesaplama olduğunu düşünelim.
Alpha, beta ve theta isimli 3 tane ayrı double değeri hesaplaması ve kendisini çağıran fonksiyona aktarması gerekiyor.

alpha
beta
theta

func(a, b, c, &x, &y, &z)

İlk 3 parametreye fonksiyonun hesaplamada kullanacağı değerleri gönderdim.
Son 3 parametreye de aslında fonksiyonun hesapladığı değerleri tutacak kendi değişkenlerimizin adreslerini gönderdik.

Böylece geri dönüş değeri mekanizmasıyla doğrudan fonksiyon, bize 3 tane değeri aktaramıyorken,
böyle bir modelle fonksiyon, çağıran koda istenilen sayıda değeri aktarabiliyor.

*/


