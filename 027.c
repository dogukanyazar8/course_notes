/*

C dilinde bir fonksiyonun parametresinin pointer olması demek, 
call by reference dediğimiz fonksiyon çağrı biçiminin oluşturulması demek.

Bir fonksiyon bir fonksiyona bir nesnenin kendisini geçecekse, C dilinde bunun karşılığı pointer semantiği.
Yani fonksiyonun parametre değişkeni pointer olur. Fonksiyonu, göndermek istediğimiz değişkenin, nesnenin adresiyle çağırırız.

----

const anahtar sözcüğü

Java, C# gibi dillerde bu tür fonksiyonlar söz konusu olduğu zaman, 
bu dillerin semantik yapısı gereği, fonksiyon bu değişkenlerden hangisini okuma amaçlı kullanacak, 
hangisini yazma amaçlı kullanacak, bunu dilin araçları doğrudan söylemiyor.

Fakat C ve C++'da const anahtar sözcüğü bu niyeti de gösteriyor.

void add_matrix (Matrix *presult, const Matrix *p1, const Matrix *p2);

Buradaki const anahtar sözcüğü bu parametreye adresi gelen nesnelerin fonksiyon tarafından salt okuma amaçla kullanılacağını,
yani bu nesnelerin fonksiyon tarafından değerinin değiştirilmeyeceğini anlatıyor.

Fonksiyon bu nesnelerin değerini değiştirmeyecek ve bu nesnelere bir değer yazmayacak.
Bunları salt okuma amaçlı kullanacak, erişim amaçlı.

const anahtar sözcüğünün olmaması, tam tersi bir anlam katıyor.
Fonksiyonun amacı o nesnelerin değerini değiştirmek, o nesneye bir değer yüklemek.

const anahtar sözcüğü etrafında biçimlenen bu semantik yapıya C ve C++ dillerinde const semantiği deniyor.

Pointer parametrenin kullanılmasının bir nedeni daha var. Bu da diziler.

int türden bir değeri bir fonksiyona göndermek için call by reference veya call by value yoluyla olabilir.
Ama bir dizinin bir fonksiyona gönderilmesi C dilinde yalnızca call by reference yoluyla oluyor.

Yani bir dizinin kopyalanarak fonksiyonlara aktarılması gibi bir sentaks aracı veya semantik yapı yok.
Bir fonksiyon bir fonksiyona bir dizi gönderecekse, bu alışveriş mutlaka adres semantiğiyle yapılmalı.

Call by reference nerelerde karşımıza çıkacak, özetle.

1) Geri dönüş değeri mekanizmasının yerine kullanılması. Fonksiyonun hesapladığı değerin, fonksiyona gönderilen adresteki nesneye yazılması.

2) Hesaplama yapılması için ihtiyaç duyulan input değerler var. O değerleri değiştirme amacıyla değil, onları alıp kullanma amacı var.

3) Fonksiyon birden fazla değer iletmeye yönelik yazılmış ama bir fonksiyonun bir tane parametre değişkeni olur. Fonksiyonumuz ise 4 tane 5 tane değer iletecek.
En sık kullanılan kullanılan araçlardan biri, fonksiyonun çağıran koda kaç tane değer iletmesi gerekiyorsa, çağıran kodun bu değerleri tutacağı nesnelerin adreslerini istemesi ve adreslerini aldığı nesnelere bu değerleri yazması.

4) Eğer bir fonksiyon bir fonksiyona bir diziyi iletecekse, bir diziyi bir fonksiyona aktarmanın tek yolu fonksiyonun parametre değişkenin pointer olması.

Ayrıca fonksiyonun geri dönüş değeri türü dizi olamaz. Diziler fonksiyondan fonksiyona adres yoluyla aktarılıyorlar. 
Kopyalama yoluyla yapılmasına dair bir araç söz konusu değil.

Gereksiz yere, ortada pointer parametre kullanılması gerekmeyen senaryoda pointer parametre kullanmamak lazım.

------

const anahtar sözcüğü - C ve C++ dillerinde en önemli anahtar sözcüklerden biri.

constant sözcüğünden kısaltılmış bir anahtar sözcük.

const anahtar sözcüğüyle bir değişkenin bildiriminde const anahtar sözcüğünü kullanabiliyoruz.

const anahtar sözcüğüyle tanımlanan değişkenlere const değişkenler deniliyor.

Böyle bir değişken, değeri hiç değişmeyecek bir değişken.

const variable -> oxymoron 

variable (vary)

--------

int main()
{
    const int x = 10;
}

x hayata 10 değeriyle geliyor ve hayatı boyunca değeri hep 10 olarak kalacak.

const anahtar sözcüğüyle tanımlanmış bir değişkenin değerini değiştirmek doğrudan sentaks hatasıdır.

--------

const int a[] = {1, 2, 3, 4, 5};

Bu bir dizi de olabilir. Dizinin elemanlarının değerini değiştiremeyiz.
Teki bir dizi const olabildiği gibi, bir dizinin elemanları da const olabilir.

const anahtar sözcüğünün tür belirten anahtar sözcükle yeri değişebilir. Bir anlam farkılılığı yok.

const int x = 10;
int const x = 10;

ikisi de aynı anlamdadır.

const = read only

-------

const vs macro 

Bazı durumlarda bunlar birbirlerine alternatif olabilirler.

Fakat const ile bir değişken bildiriyoruz. Bu ismi derleyici görüyor, bu değişkenin bir adresi ve kapsamı var, bellekte bir yer kaplıyor.

Ama biz bir makro oluşturup, bunu kod içinde kullanırsak, derleyici bir isim görmeyecek.
Derleyicinin çalışmasından önce ön işlemci programı yer değiştirme yapacak.

-------

const correctness
const doğruluğu

Bütün c programlarının const correct olması gerekiyor. 

const olması gereken bütün değişkenlerin const yapılmasından,
const olmaması gereken bütün değişkenlerin const yapılmamasından biz sorumluyuz.

Kodun kalitesini belirleyen en önemli faktörlerden biri.

-------

Neden const nesne kullanıyoruz?

const anahtar sözcüğü bir çok durumda lojik hataların sentaks hatası seviyesine yükseltimesini sağlıyor.

Bir çok programda, kodda, bizim lojik açıdan değerinin değişmemesi gereken varlıklarımız var, yani o varlıkların değerinin değişmesi lojik bir hata.
Biz o varlıkları değişkenlerle temsil ederken, o değişkenleri const yaparsak, o değişkenleri değiştirmeye yönelik kodlar sadece lojik hata olarak kalmayacak, artık sentaks hatası olacaklar.

Mesela primes isimli bir dizimiz var. Bu dizi asal sayıları içersin. Örnek olarak ilk 20 asal sayı.

Indeks ile dizideki asal sayılara erişeceğimizi düşünelim. Indeksi n olan asal sayiyi kullanmak istiyoruz.
n degerini bu diziye indeks yaptığımızda, 10. asal sayıyı veya istediğimiz indeksdeki asal sayiyi bulabiliriz.
Lookup table.



   int primes[] = { 
   2 , 3 , 5 , 7 , 11 , 
   13 , 17 , 19 , 23 , 29 , 
   31 , 37 , 41 , 43 , 47 , 
   53 , 59 , 61 , 67 , 71
   };

Eğer yazdığımız kodlardan biri, bu dizinin bir elemanını değiştirirse, bu lojik bir hatadır.

Örneğin bu dizinin 2 indisli elemanını aşağıdaki gibi değiştirirsek, dizinin 2 indisli elemanı 5 değil de 6 olacak.

++primes[2];

Ama bu dizi const olsaydı, bu dizinin 2 indisli elemanını değiştirme girişimi lojik hata olmaktan çıkacak aynı zamanda sentaks hatası olacak.

Lojik açıdan değişmemesi gereken değişkenlerimiz varsa, bunları const anahtar sözcüğüyle tanımlamalıyız ki bu const nesnenin değerini değiştirmeye yönelik kodlar doğrudan sentaks hatası olsun.

Buna her zaman uymamız gerekiyor.

{
   const int primes[] = { 
   2 , 3 , 5 , 7 , 11 , 
   13 , 17 , 19 , 23 , 29 , 
   31 , 37 , 41 , 43 , 47 , 
   53 , 59 , 61 , 67 , 71
   };

-----

Mesela tarih bilgisi tutan Date türünden bir nesnemiz olsun.
Bu değişkenin değerinin 10 Mayıs 1994 olarak kalmasını istiyorsak mutlaka const anahtar sözcüğüyle tanımlamamız lazım.

const anahtar sözcüğü kodu okuyana da yardımcı oluyor.

int a[] = { 2 , 3 , 5 , 7 , 11 };

Mesela bu dizide const anahtar sözcüğünün olmamasından, bu dizinin salt erişim amaçlı kullanılmayacağını anlıyoruz.
Bu dizinin elemanlarının değerinin kodlar tarafından değiştirilme ihtimali olduğunu anlıyoruz.
Bu mutable bir varlık. Değiştirilebilir.

const int a[] = { 2 , 3 , 5 , 7 , 11 };

Ama const anahtar sözcüğüyle tanımlanan bir varlık, immutable.

const anahtar sözcüğü niyeti anlatıyor. intent.

-----

Ayrıca derleyiciye de yardımcı oluyor. 
C ve C++ derleyicilerin en büyük özelliği optimizasyon yapmaları. Kodu bizim yazdığımız gibi değil, en az işlem yapılacak şekilde teknikler kullanıyorlar.
Compiler optimizations.

Derleyicinin kodu iyi bir şekilde optimize edebilmesi, bazı faktörlere de bağlı.

Eğer derleyici koda bakarak bazı nesnelerin değerlerinin değişmeyeceğini anlayabiliyorsa, daha iyi bir optimizasyon, daha iyi bir kod üretme şansı var

Dolayısıyla const olması gereken varlıkları const anahtar sözcüğüyle tanımlarsak, derleyicinin daha iyi optimizasyon yapması için zemin hazırlamış oluyoruz.

-----

const anahtar sözcüğü ile tanımlanan bir değişkeni sentaks hatası engelini aşarak değiştirme girişiminde bulunursak, bu her zaman tanımsız davranış.

const bir nesnenin değerini değiştirme girişini her zaman tanımsız davranış.

------

Uyarı Mesajı Veren

#include <stdio.h>

int main()
{
   const int x = 10;
   int *p = &x;      //C++ dilinde sentaks hatası. C dilinde geçerli.

   *p = 20;          //ub - tanımsız davranış
}

------

Uyarı Mesajı Vermeyen

#include <stdio.h>

int main()
{
   const int x = 10;
   int *p = (int *)&x;      //C++ dilinde sentaks hatası. C dilinde geçerli.

   *p = 20;                //ub - tanımsız davranış
}

------

Aşağıdaki const anahtar sözcüğü pointer değişkenin tanımında kullanılan asterisk atomundan, yıldız deklaratöründen (*) önce kullanılmış

   int x = 10;

   int* const ptr = &x;

Burada ise const anahtar sözcüğü asterisk atomundan daha önce kullanılmış. Buradaki const anahtar sözcüğünün anlamı farklı.

   int x = 10;
   
   const int* ptr = &x;

Önemli olan asterisk atomundan önce olup olmadığı. Mesela aşağıdaki iki bildirim de aynı anlamda.

   const int * p = &x;
   int const * p = &x;

-----

1 ) const anahtar sözcüğünün asterisk atomundan sonra kullanılması durumu

Bu şekilde tanımlanan değişkenler için const pointer terimi kullanıyor.
const pointer to int - kendisi const pointer

Burada kastedilen, ptr değişkenin değerinin değişmeyeceği.
ptr hayatı boyunca hep x'i gösterecek.

   int x = 10;

   int * const ptr = &x;

Mesela burada const anahtar sözcüğü olmasaydı, aşağıdaki gibi ptr değişkeninin değerini değiştirebilirdik.

   int x = 10;
   int y = 20;

   int * ptr = &x;
   ptr = &y;

Ama const anahtar sözcüğü varsa, bu deyim sentaks hatası olacak.

   int x = 10;
   int y = 20;

   int * const ptr = &x;
   ptr = &y;   //gecersiz

Eğer pointer değişkenimizin lojik açıdan hep aynı nesneyi göstermesi gerekiyorsa, başka bir nesnenin adresini tutması lojik bir hataysa,
const anahtar sözcüğünü asterisk atomundan sonra kullanabiliriz.

C'de yoğun olarak kullanılmıyor fakat C++'da böyle pointerları betimlemek için top level const terimi kullanılıyor.

Ayrıca pointer değişkenimizi içerik operatörünün operandı yaparak, eriştiğimiz nesnenin değerini değiştirmek sentaks hatası değil.
Sentaks hatası değil çünkü böyle bir şeyi ifade etmedik, böyle bir söz vermedik.

   int x = 10;

   int * const ptr = &x;
   *ptr = 87; //gecerli

--------------

2 ) const anahtar sözcüğünün asterisk atomundan önce kullanılması durumu

const'un tür belirten anahtar sözcükten önce ya da sonra kullanılmasının anlamsal açıdan bir farkı yok.

   int const * ptr = &x;
   const int * ptr = &x;

Bu iditomatik yapı için pointer to const int terimi kullanılıyor.

pointer to const int - gösterdiği yer const

C++'da böyle pointerları betimlemek için low level const terimi kullanılıyor.

Burada verdiğimiz söz ptr'nin gösterdiği nesneye eriştiğimizde, bunu salt okuma amaçlı kullanacağım, asla bu nesneyi değiştirmeyeceğim.

Dolayısıyla aşağıdaki kod sentaks hatası olacak.

   int x = 10;

   int const * ptr = &x;
   *ptr = 40;

Burada ptr'nin değerini değiştirebiliriz, sentaks hatası olmaz.

   int x = 10;
   int y = 10;

   int const * ptr = &x;
   ptr = &y;

-----

Mesela aşağıdaki bir tanımlama yaptığımızda x = 30 ataması sentaks hatası olmaz.
Çünkü const ptr'nin bildiriminde kullanılıyor.

   int x = 10;

   const int * ptr = &x;
   x = 30;

-----

#include <stdio.h>

int main()
{
   int x = 10;
   int y = 20;

   int * const ptr1 = &x; //const pointer to int - kendisi const pointer
   
   ptr1 = 48;     //gecersiz
   *ptr1 = 48;    //gecerli
   
   int const * ptr2 = &y; //pointer to const int - gösterdiği yer const

   ptr2 = 48;     //gecerli
   *ptr2 = 48;    //gecersiz
}

-----

Bir pointer'ı bir nesneye salt erişim yani okuma amaçla kullanacaksak mutlaka const anahtar sözcüğünü kullanmamız gerekiyor.
Bunun en sık karşılaşılan yeri pointerların parametre değişkenleri olması.

void func(int *ptr);

Bu fonksiyona baktığımızda const anahtar sözcüğünün olmamasından, bu fonksiyonun bir set fonksiyonu olduğunu anlıyoruz.

Türden bağımsız olarak, aynı anlamı çıkarmamız gerekiyor.

Bu fonksiyon bizden bir nesnenin adresini istiyor, adresini aldığı nesneyi değiştirmek, ona bir değer yüklemek için.

void func(T *ptr)
//set function
//setter
//mutator

----

Bu fonksiyon bizden bir nesnenin adresini istiyor, adresini aldığı nesneyi değiştirmeyecek, salt okuma amaçla erişecek.

void func(const T *ptr)

Pointer parametreli bir fonksiyon yazarken dikkat etmemiz gereken ilk nokta budur.

----

const anahtar sözcüğü iki yerde birden de kullanılabilir.

const pointer to const int

Bu durumda bahsettiğimiz iki anlam birleşiyor.

const int * const p = &x;

sondaki const -> p'nin değerini değiştiremeyiz.

baştaki const -> *p'yi salt okuma amaçlı kullanabiliriz.

   int x = 10;
   int y = 50;

   const int * const p = &x;

   *p = 20; // gecersiz
   p = &y; // gecersiz

----------------------

Özet geçmek gerekirse

T * ptr = &x;        -> ptr'nin gösterdiği nesneyi değiştirebiliriz.

T * const ptr = &x   -> ptr'nin gösterdiği nesneyi değiştirebiliriz. ptr'nin değerini değiştiremeyiz. ptr hayatı boyunca x'i gösterecek. const pointer to int top level const.

const T * ptr = &x   -> ptr'nin gösterdiği nesneyi değiştiremeyiz. ptr'nin değerini değiştirebiliriz. ptr salt okuma erişimi için x'i gösteriyor demek. pointer to const int. low level const.

-----

void func(T *ptr)          -> Bu bir set fonksiyonu.
void foo(const T *ptr)     -> Bu bir access fonksiyonu

-----

C'nin standart kütüphanesinde bulunan bazı fonksiyonlardaki const anahtar sözcüğü.

strlen()    - bu fonksiyonun parametre değişkeni const char * (yazının uzunluğunu hesaplayan fonksiyon)

_strrev()   - bu fonksiyonun parametre değişkeni char * (yazıyı ters çeviren fonksiyon)

strcpy()    - ilk parametresi char *, ikinci parametresi const char * (ilk parametresi kopyalamanın yapılacağı adres, ikinci parametresi ise kaynak yazının adresi)
            - ilk parametredeki yazıya yazma amaçlı erişecek, ikinci parametredeki yazıya salt okuma amaçlı erişecek.

strcmp()    - ilk parametresi const char *, ikinci parametresi const char *

Bu kurala bizim yazdığımız bütün fonksiyonların da uyması gerekiyor. 
C'de bir programın kalitesini gösteren en önemli faktörlerden biri.

------------------

Örnek olarak bir süre önce yazdığımız print_array fonksiyonu. (print_array fonksiyonu bir int dizinin elemanlarını ekrana yazdırıyor)

print_array fonksiyon bildirimi -> void print_array(const int* p, int size);

Bu fonksiyon diziyi değiştirmek amaçlı değil, dizinin elemanlarını salt okumak, erişmek amaçlı kullanılıyor.

------------------



*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{
   char a[SIZE] = "dogukanyazar";
   char b[SIZE] = "dogukanyazar";

   printf("comparison = %d\n", strcmp(a,b));
}