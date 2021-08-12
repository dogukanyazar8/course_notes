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

Bundan dolayı fonksiyon parametresi -> const int *

------------------

Örnek olarak bir süre önce yazdığımız sort_array fonksiyonu. (sort_array fonksiyonu bir int dizinin elemanlarını sıralıyor)

sort_array fonksiyon bildirimi -> void sort_array(int* p, int size);

Bu fonksiyon diziyi değiştirmek amaçlı kullanılıyor.

Bundan dolayı fonksiyon parametresi -> int *

------------------

Parametreyi const int * yani low level const yapmamızın nedeni hem kodun niyetini, programıncının niyetini belli ediyor.
Aynı zamanda bufonksiyonun kodunu yazarken, pointer vasıtıyla değiştirmememiz gereken nesneleri yanlışlıkla değiştirdiğimizde sentaks hatası olacaktı. 

------------------

Ayrıca top level const, pointer parametre olarak değil de daha çok yerel veya global pointerler için karşımıza çıkar.

Mesela embedded bit programda bir pointer değişkenimizin bir register adresi tutması ve bunun değerinin asla değişmemesi gerekiyor. O zaman bunu top level const yapabiliriz. 

int *const p = (int *)0xB800;

const anahtar sözcüğünü yukarıdaki gibi kullandığımızda, bir artık p'nin gösterdiği değerin hayatı boyunca değiştirilemeyeceğini ifade ediyoruz.

------------------

Pointer Aritmetiği

Pointer aritmetiğiyle anlatılmak istenilen adreslerle ilgili yapılan bazı işlemlerde dilin sentaks kuralları kastediliyor.

Adreslerle yapılan toplama, çıkarma, ++ operatörünün adres olması, -- operatörünün adres olması gibi bazı işlemler tam sayılar üzerinde yapılan toplama çıkarma işlemleri gibi değil.

------------------

C dilinde bir adresle bir tam sayı toplanabilir. 
C dilinde bir tam sayıyla bir adres toplanabilir.
C dilinde bir adresten bir tam sayı çıkartılabilir.
C dilinde bir tam sayıdan bir adresin çıkartılamaz. Sentaks hatasıdır.

adr ifadesi bir adresi, ival de bir tam sayıyı gösterdiğini düşünelim.

adr + ival //legal
ival + adr //legal
adr - ival //legal
ival - adr //illegal

Yukarıdaki bütün bu ifadelerin değeri bir adrestir. Yani bu işlemlerden elde edilen değer bir adrestir.

------

#include <stdio.h>

int main()
{
   int *ptr;

   5 - ptr; //sentaks hatası
}

------

Bir nesne adresine 1 toplarsak, bellekte ondan sonra gelen nesnenin adresini elde ediyoruz.

Bir dizinin bir elemanının adresine 1 toplarsak, bu dizinin bir sonraki elemanının adresini elde ediyoruz.
Bir dizinin bir elemanının adresinden 1 çıkartırsak, bu dizinin bir önceki elemanının adresini elde ediyoruz.

------

5 elemanlı arr isimli bir dizimiz var. 

Eğer bu arr dizisinin ilk elemanının adresi 5600 ise, ikinci elemanının adresi 5604'dür. int türü 4 byte olduğuna göre.

Şimdi bu dizinin ilk elemanının adresine 1 topladığımızda, eğer bu işlem tam sayı toplama işlemi gibi olsaydı 5601 elde edecektik.

Ama pointer semantiğiyle 5601 değil, 5604 olacak.

-------

#include <stdio.h>

int main()
{
   int arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%p\n", &arr[i]);
   }
}

Adreslerde hexadecimal sayı sistemi kullanılıyor, dizinin elemanlarının adreslerini yazdırdık. int türü 4 byte olduğu için 4'er 4'er artıyor.

Kodun ekran çıktısı:

0028ff28
0028ff2c
0028ff30
0028ff34
0028ff38

-------

Yukarıdaki kod ile bağlantılı olarak, dizinin ilk elemanının adresiyle döngü değişkenini toplayıp, döngünün her turunda ekrana adres bilgisini yazdırır gibi yazdırıyoruz.
Dizinin herhangi bir elemanının adresine 1 eklendiğinde, bir sonraki elemanının adresini elde ederiz. Aşağıdaki kod bunun bir örneği.

#include <stdio.h>

int main()
{
   int arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%p %p\n", &arr[i], arr + i);
   }
}

Kodun ekran çıktısı:

0028ff28 0028ff28
0028ff2c 0028ff2c
0028ff30 0028ff30
0028ff34 0028ff34
0028ff38 0028ff38

-------

Eğer arr dizisinin türü int değil de char türünden olsaydı. Bu sefer dizinin elemanlarının adresleri 4'er değil de 1'er olarak artacaktı.
Yine int türünde olduğu gibi, char türünden de bir dizinin elemanının adresiyle 1 topladığımızda, bir sonraki elemanın adresini elde ederiz.

#include <stdio.h>

int main()
{
   char arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%p %p\n", &arr[i], arr + i);
   }
}

Kodun ekran çıktısı:

0028ff37 0028ff37
0028ff38 0028ff38
0028ff39 0028ff39
0028ff3a 0028ff3a
0028ff3b 0028ff3b

-------

Eğer arr dizisinin türü int değil de double türünden olsaydı. Bu sefer dizinin elemanlarının adresleri 4'er değil de 8'er olarak artacaktı.
Yine int türünde olduğu gibi, double türünden de bir dizinin elemanının adresiyle 1 topladığımızda, bir sonraki elemanın adresini elde ederiz.

#include <stdio.h>

int main()
{
   double arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%p %p\n", &arr[i], arr + i);
   }
}

Kodun ekran çıktısı:

0028ff10 0028ff10
0028ff18 0028ff18
0028ff20 0028ff20
0028ff28 0028ff28
0028ff30 0028ff30

-------

Eğer bu kural olmasaydı, bir dizinin bir elemanının adresinden yola çıkarak, 
dizinin bir önceki veya bir sonraki elemanının adresini elde etmek istediğimizde bizim derleyicimiz için aşağıdaki değerleri kullanmamız gerekti.

char     dizi için 1
short    dizi için 2
int      dizi için 4
double   dizi için 8

Dilin kurallarına göre bir adres ile bir tam sayı topladığımızda her zaman ondan sonra gelen nesnenin adresini elde ederiz.

Tabiki sadece 1 toplamak zorunda değiliz, bu 5 de olabilirdi. Bir adresle 5 topladığımızda, o adresten 5 sonra gelen nesnenin adresini elde ederiz.

-------

Bir dizinin n indisli elemanının adresini almakla, dizinin ilk elemanının adresine n eklemek arasında hiçbir fark yok.

&a[n] <----> a + n

Bu kurala göre, arr dizisinin 3 indisli elemanın adresi demek, aslında arr + 3 demek.

&a[3] <----> a + 3

--------

#include <stdio.h>

int main()
{
   int arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%d %d\n", arr[i], *(arr + i));
   }
}

--------

a[i]
*(a + i)
*(i + a)
i[a]

--------

#include <stdio.h>

int main()
{
   int arr[5] = { 0, 1, 2, 3, 4};

   for (int i = 0; i < 5; ++i){
      printf("%d %d %d\n", arr[i], *(arr + i), *(i + arr));
   }
}


--------

#include <stdio.h>

int main()
{
   int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int *p = arr;

   printf("%d\n", *p);
   ++p;
   printf("%d\n", *p);
}

--------

printf çağrısındaki ifadelerin hepsi dizinin i indisli elemanını ekrana yazdırıyor.

#include <stdio.h>

int main()
{
   int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int *p = arr;

   for (int i = 0; i < 10; ++i){
      printf("%d %d %d %d\n", arr[i], *(arr + i), *(i + arr), *p);
      ++p;
   }
}

--------

#include <stdio.h>

int main()
{
   int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

   //int *ptr = &arr[5];
   int *ptr = arr + 5;

   printf("%d\n", *ptr);
}

--------

C dilinde toplama operatörünün her iki operandı adres olamaz. Adres ile adres toplanamaz, sentaks hatasıdır. 

C dilinde çıkarma operatörünün her iki operandı adres olabilir. İki adres birbirinden çıkartılabilir. Bu işlemden elde edilen değer işaretli tamsayıdır.

#include <stdio.h>

int main()
{
   int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   
   int *p1 = &arr[5];
   int *p2 = &arr[8];

   printf("p1 - p2 = %d\n", p1 - p2);
   printf("p2 - p1 = %d\n", p2 - p1);
}

Kodun ekran çıktısı:

p1 - p2 = -3
p2 - p1 = 3

Adreslerin ait olduğu nesnelerin türünden bağımsız olarak, yine aynı sonucu elde ederiz.
Örneğin int değil de double olsaydı pointer türü, değişen bir şey olmayacaktı bu kod işlem için.
--------

Kısaca Notlar.

adres + tamsayı = adres
tamsayı + adres = adres
adres - tamsayı = adres
tamsayı - adres = sentaks hatası
adres + adres = sentaks hatası
adres - adres = işaretli tamsayı

Yukarıda legal olan işlemlerin, doğru ya da anlamlı olması için aynı dizinin elemanlarının adresleri söz konusu olması gerekiyor.

int x = 10;
int y = 20;

&x - &y ->>>> Bu işlem legal. Fakat bu koddan elde edebileceğimiz hiçbir fayda yok.

Bağımsız, tekil değişkenlerin adreslerini birbirinden çıkartmanın hiçbir anlamı yok.
Bütün bu işlemlerin anlamlı olması için aynı dizinin elemanlarının adresleri olması gerekir.

--------

index / subscript operatörü []

Operatör öncelik seviyesine göre 1. öncelik seviyesinde.

1 - [ ] () . -> 

Öncelik yönü soldan sağa, binary operator.

Bir operandı köşeli parantezin içinde, diğer operandı parantezin dışında.

Derleyici x[y] ifadesiyle karşılaştığında,

Köşeli parantezin dışındaki operandı, toplama operatörüyle köşeli parantezin içindeki operand ile toplayacak bir ifade oluşturuyor.
Buradan elde ettiği ifadeyi de içerik operatörünün operandı yapıyor.

x[y] == *(x + y)

Bu operatörün dıştaki operandının bir dizi olma zorunluluğu yok.
Ya da içteki operandın pozitif bir tam sayı olma zorunluluğu yok.
Önemli olan dıştaki operand ile içteki operandın toplanmasıyla bir adresin elde edilmesi.

Çünkü içerik operatörünün operandı bir adres olmak zorunda.

Bu operatörün dıştaki ya da içteki operandı bir pointer değişken de olabilir.

a[i] == *(a + i)
i[a] == *(i + a)

------

#include <stdio.h>

int main()
{
   int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   for (int i = 0; i < 10; ++i)
      printf("%d %d\n", a[i], i[a]);
}

------

#include <stdio.h>

int main()
{
   int x = 10;

   ++(&x)[0];

   //++x* (&x + 0); x'in değeri 1 artacak.

   printf("%d\n", x);
}

------

ptr[0] == *ptr

a[0] == *a

------

Bu işlemlerde dizinin taşması tabiki de tanımsız davranıştır.
Toplama çıkarma işlemlerinde eriştiğimiz bellek alanı bize ait bir bellek alanı değilse, bu kesinlikle tanımsız davranıştır.

#include <stdio.h>

int main()
{
   int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int *ptr = a + 5;

   printf("%d\n", *ptr);   //5
   printf("%d\n", ptr[0]); //5
   printf("%d\n", ptr[3]); //8
   printf("%d\n", ptr[-2]); //3
   printf("%d\n", ptr[9]); //tanımsız davranış
}

------

Köşeli parantez operatörü aslında bir kısayol gibi. 
Bu operatör olmasaydı aşağıdaki gibi kullanacaktık.

a[b] yerine *(a + b)

------

SORU: 

ptr, a isimli bir dizinin bir elemanını göstermektedir.
ptr'nin gösterdiği dizi elemanının indeksi nedir?

ptr - a

Elimizde bir dizinin bir elemanının adresi varsa, bizim elimizde o dizinin o elemanının indeksi de var.

Adresten indekse geçiş yapmak için, dizinin elemanının adresinden dizinin ilk elemanının adresini çıkartacağız.

Diziler söz konusu olduğunda, indeksten adrese, adresten indekse geçiş yapabiliriz.

------

SORU: 

ptr, a isimli bir dizinin 5 indisli elemanını göstermektedir.
ptr'nin gösterdiği dizi elemanının adresi nedir?

a + 5
ptr + 5

------

Adresten indekse geçmek için dizinin başlangıç adresini çıkartacağız.
Indeksten adrese geçmek için dizinin başlangıç adresini toplayacağız.

*/

#include <stdio.h>

int main()
{

}
