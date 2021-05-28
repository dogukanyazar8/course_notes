/*

Ders18

Fonksiyonel Makrolar - Function-like Macro

Aslında burada önişlemci programı kullanarak bir hile yapıyoruz. Fonksiyon çağrısı gibi bir görüntü var ama ortada fonksiyon yok.
Fonksiyon çağrı ifadesine benzeyen kodu önişlemci program makro olarak alıyor ve bir yer değiştirme işlemi yapıyor.

Peki bunu neden yapıyoruz?

Bunu yapmanın farklı nedenleri var ama en tipik nedenlerden biri maliyet.
Öyle fonksiyonlar var ki, bunları gerçekten fonksiyon olarak tanımlarsak, fonksiyona giriş ve fonksiyondan çıkış kodlarının maliyeti gereksiz yere toplam maliyete eklenecek.
Özellikle çok sayıda çağrılması söz konusu olan ve kodu küçük olan fonksiyonlar için bu ciddi bir kazanç oluşturuyor.

#define isleap(y)     ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

Makrolara bir aday da, inline expansion kavramı.

Derleyicilerin en önemli aktivitelerinden biri kodu optimize etmeleri. Compiler optimization.
Yazdığımız kodu, en uygun assembly kodunu üretmek için düzenliyor.

Derleyici kod optimizasyonu ne kadar geniş bir kod bloğu üzerinde yaparsa, o kadar iyi optimize etme şansı var.

/////kod
/////kod
/////kod
func();
/////kod
/////kod
/////kod

Fonksiyon çağrıları, derleyicinin optimize etmeye aday olduğu kod bloğunu küçültüyor, bölümlüyor.
Ama yukarıdaki fonksiyon olmasaydı, fonksiyonun açılmış kodu olsaydı, isleap gibi, derleyici yukarıdaki kodun tamamını optimize edebilecekti.

===========================================================================

1 - Makrolar türden bağımsız ama fonksiyonlar bir tür kavramına sahip.

Bir kere makro, fonksiyon değil. Fonksiyonları elimine etmek için kullandığımız bir araç.
Makrolar, türden bağımsız.

#define max2(a, b) ((a) > (b) ? (a) : (b))

Mesela burada bir tür yok. Tür olmadığı için tür kontrolü de yok. Ama bu bir fonksiyon olsaydı, argümandan parametre değişkenine bir tür kontrolü olacak.

Makrolar generic, fonksiyonlar türe bağlı.

Bu durum çoğunlukla, tür kontrolünün yapılması fonksiyon yönünden avantaj.
Makronun da, ayrı ayrı 3 tane 4 tane fonksiyon yazmak yerine, farklı türler için tek bir seferde yazılabilir.

2 - Makrolar kaynak kodu, oluşturulan exe kodu büyütme eğilimindedir. Özellikle gömülü ortamda istemediğimiz bir durum olabilir. Alan kısıtlı olduğu için.

Mesela isleap örneği. 

#define isleap(y)     ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

Ben bu kaynak dosyada, 20 ayrı yerde isleap fonksiyonuna çağrı yapmış olalım. Nerede çağrı yapmış olursam, orada yer değiştirme işlemi yapılmış olacak.
Derleyici bu işlem kodlarını tekrar tekrar üretme durumunda. Bu da exe kodun büyümesi anlamına geliyor.
Oysa bu bir fonksiyon olsaydı, fonksiyonun kodu bir kere derlenecekti, bu fonksiyona çağrı olacaktı.

Her makro derlenmiş kodu büyütür diyemeyiz ama çoğunlukla aynı makro birden fazla yerde kullanılmışsa, kaynak kodu büyütme eğilimindedir.

3 - Makrolar Debugger dostu değil fakat fonksiyon Debugger dostu. Debugger-friendly

Hangi debugger programı olursa olsun, fonksiyonlar için mükemmel destek veriyorlar. 
Mesela hangi fonksiyonun hangi fonksiyonu çağırdığını debugger takip edebiliyor, veya fonksiyondan fonksiyona geçişlerde durdurabiliyoruz.
Fonksiyon debugger friendly. Ama makro fonksiyon olmadığı için bunu demek debug ederken giriş çıkışları görmemiz mümkün değil.

4 - Güvenlik, hata yapma riski

Makrolar, güvenli değil. Bir makroda makronun yanlış kullanımıyla hata alma riski yüksek. Çok dikkatli olunması gerekiyor.

#define square(x)   ((x) * (x)) -> Eğer bu fonksiyona bir yan etkisi olan bir ifade geçersek, duruma göre ya tanımsız davranış olacak ya da beklentinin dışında bir kod çalışacak.
a++ gibi bir ifade ile çağrı yapmak gibi.

Makro argümanının makro açılım listesinde birden fazla kez kullanıldığı yerde bu güvenlik bu problemi var.

Bazı derleyicilerin eklentileri var. Mesela GCC derleyicisinde bu tür makrolar için gcc statement expression var.

https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html

#define maxint(a,b) \
  ({int _a = (a), _b = (b); _a > _b ? _a : _b; })

Küme parantezi bir ifade olarak ele alınacak. 

Bu ifadede _a bir değişkenin ismi, buna a ile ilk değer verilmiş.
Bu ifadede _b bir değişkenin ismi, buna b ile ilk değer verilmiş.

GCC'nin kurallarına göre bu ifadenin değeri _a > _b ? _a : _b; }) bu ifadenin değeri.

Biz artık bloğun içinde tanımlanmış yerel değişkenler olan a ve b'yi kullanmış oluyoruz.

-----------------------------------------------------------------------------------------

Ayrıca çok önemli bir nokta.

C ve C++'da nasıl değişkenlerin adresleri varsa, fonksiyonların da adresleri var.

Fonksiyon adreslerine function pointer deniliyor. Ve bir çok iş fonksiyonların adreslerini kullanarak yapılıyor.

Mesela bir fonksiyona bir fonksiyonun adresini gönderiyoruz. Makronun adresi yok, function pointer gereken yerde, makro kullanamayız.

-----------------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = 'A';

    if isupper(c)
        printf("ok!");
}

Yukarıdaki programda bir hata var mıdır?

Yukarıdaki kodda, derleyicide isupper fonksiyonu, bir fonksiyon şeklinde değil de, bir fonksiyonel makro şeklinde olabilir.

Dolayısıyla bu makro açıldığında, aşağıdaki gibi olacak ve herhangi bir hata olmayacak.

#define isupper(c) ((c) >= 'A' && (c) <= 'Z')

#include <stdio.h>
#define isupper(c) ((c) >= 'A' && (c) <= 'Z')

int main()
{
    int c = 'a';

    if isupper(c)
        printf("ok!");
}

-----------------------------------------------------------------------------------------

Makro parametleri bir tane olabilir, birden fazla olabilir veya hiç olmayabilir. Bu da bir zorunluluk değil.

Örnek:

#include <stdio.h>
#define randomize() srand((unsigned) time(NULL))

int main()
{
  //randomize();
  srand((unsigned) time(NULL));
}

Önişlemci, randomize() yerine srand((unsigned) time(NULL)) bu ifadeyi koyuyor.

Bazen fonksiyonel makroların amacı sadece bir kısa yazım sağlamak.

Doğrudan srand((unsigned) time(NULL)) bunu yazsak da derleyici aynı kodu görüyor.

Daha uzun, verbose kodlar yazmaktansa, daha fazla öğe içeren kodlar yazmaktansa, onları önişlemci programa yazdırmak daha iyi.

-----------------------------------------------------------------------------------------

Farklı bir örnek, mesela aşağıdaki gibi ifadeleri sık sık kullanacağımızı düşünelim.
Hem kodun okunması zor, hem de kodu yazarken hata yapma riski yüksek.
Burada bunu makro yapmamızın amacı daha kısa daha kolay okunur bir ifade yazmak, böylece ifadeyi yazarken de hata yapma riskini azaltmak.

ptr->a[i] * ptr->a[k]

ptr->a[5] * ptr->a[7]

ptr->a[x + y] * ptr->a[z - t]

Makro:

#define getval(x, y) (ptr->a[(x)] * ptr->b[(y)])

getval(i, k)
getval(5, 7)
getval(x + y,  z - t)

-----------------------------------------------------------------------------------------

C'nin operatörleri olduğu gibi önişlemci programın da operatörleri var. Bunlar derleyicinin operatörleri değil.
Proprecessor operators

#   stringification operator (string yapma, dizge yapma operatörü)
##  token pasting operator   (atom yapıştırma, atom birleştirme operatörü)
    defined operator         (defined)

unary prefix

Operand olarak bir isim alıyor, bir makro argümanı olabilir.
Tek yaptığı, makro açılım listesinde böyle bir ifadeyi gördüğünde, bunun operandını çift tırnak içine alıyor.

#x

#x ifadesini önişlemci gördüğünde "x" operandı çift tırnak içine alıyor.

Örnek makro:

#include <stdio.h>
#define str(x)  #x

int main()
{
  printf(str(dogukan));
}

İlk önce, önişlemci program bu makroyu açacak. -> str(dogukan)
Önişlemci program str(dogukan) yerine "dogukan" yazacak.

Peki bu ne işe yarar?

Bazı komplex makrolarda bunu yapmak zorunda kalıyoruz. 

#include <stdio.h>
#define iprint(x) printf("%d\n", x)

int main()
{
  int x = 15, y = 20, z = 50;

  iprint(x);
  //makro açıldığında derleyicinin gördüğü:
  //printf("%d\n", x);
  iprint(x + y + z);
  //makro açıldığında derleyicinin gördüğü:
  //printf("%d\n", x + y + z);
  iprint(x * x + y * y + z * z);
  //makro açıldığında derleyicinin gördüğü:
  //printf("%d\n", x * x + y * y + z * z);
}

-----------------------------------------------------------------------------------------

iprintf fonksiyon makrosunu iprintf(x + y + z); şeklinde çağırdığımızda çıktının x + y + z = 85 şeklinde olmasını istiyoruz.

-> iprintf(x + y + z);

-> x + y + z = 85

EK BİLGİ:

Eğer kaynak kodda, aralarında boşluk olmadan yazı sabitlerini kullanırsak, derleyici derleme zamanında bunları birleştirip, tek bir string yapmak zorunda.

"dogukan"
"yazar"
"dogukan1"
"yazar1"

"dogukanyazardogukan1yazar1"

Örnek Kod:

#include <stdio.h>

int main()
{
  printf("Ben "
  "bugun "
  "koronaya "
  "yakalandim "
  
  );
}

İstediğimiz fonksiyonel makro:

#include <stdio.h>
#define iprint(e) printf(#e " = %d\n", e);

int main()
{
  int x = 15, y = 20, z = 50;

  iprint(x);
  iprint(x + y + z);
  iprint(x * x + y * y + z * z);

  iprint(x);
  //derleyicinin gördüğü: printf("x " " = %d\n", x);
  //derleyici aralarında boşluk karakteri dışında başka bir karakter bulunmadığı için yazı sabitlerini birleştirecek.
  //printf("x = %d\n", x);
  
  iprint(x + y + z);
  //derleyicinin gördüğü: printf("x + y + z = %d\n", x);

  iprint(x * x + y * y + z * z);
  //derleyicinin gördüğü: printf("x * x + y * y + z * z = %d\n", x);
}

-----------------------------------------------------------------------------------------

## token pasting operatör - operandları yazı olarak birleştiriyor.

binary infix
2 operand alıyor, ara operatör olarak kullanılıyor.

a ## b -> önişlemci bunu gördüğünde ab yapıyor.

#include <stdio.h>
#define bir(x, y)   x##y

int main()
{
  int value = 0;

  ++bir(val, ue);
  //derleyicinin gordugu kod: ++value;

  printf("value = %d\n", value);
}

Ne işe yarıyor, bazı profesyonel düzeyde önişlemciye komplex işlemlerin yaptırılmasını sağlıyor.

Aşağıdaki gibi olan n tane fonksiyonu kendimiz yazmak yerine önişlemci programa yazdırıyoruz.

int func(int a, int b)
{
    int c = a * b / 2;
    int d = (c - a) * 5;
    return c * d - 5;
}

double func(double a, double b)
{
    double c = a * b / 2;
    double d = (c - a) * 5;
    return c * d - 5;
}

Örnek Program:

#include <stdio.h>

#define make_func(t)   t func_##t(t a, t b) \
{   \
  t c = a * b / 2; \
  t d = (c - a) * 5; \
  return c * d - 5; \
}

//C dilinde function overloading yoktur. Birden fazla fonksiyonun aynı isimde olması. 
//Dolayısıyla aynı isimde olmasın diye ## operatörü func_ ile makroya argüman olarak verilen int yazının func_int yazısının elde edilmesini sağladı.

make_func(int);
make_func(long);
make_func(double);

int main()
{
  int x = func(12, 45);
}

-----------------------------------------------------------------------------------------

#include <stdio.h>
#define make_func(t)    t func_##t(t a, t b) \
{              \
  t c = a + b; \
  return c;    \
}              \

make_func(int)

int main(){
  int x = 15, y = 20;
  printf("%d",func_int(x, y)); 
}

-----------------------------------------------------------------------------------------

#include <stdio.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}

int main()
{
  int x = 10;
  int y = 45;

  swap(x, y); //Bu fonksiyonel makro çağrısında hata var. Çünkü sonunda noktalı virgül, null statement var.

  printf("x = %d\n", x);
  printf("y = %d\n", y);
}

-----------------------------------------------------------------------------------------

#include <stdio.h>

#define swap(a, b) {int temp = a; a = b; b = temp;}

int main()
{
  int x = 10;
  int y = 45;

  if (x > y)
    swap(x, y); //null statement, if'in else kısmını oluşturdu, bu yüzden sentaks hatası. else without if durumu.
  else
    ++x;
  
  printf("x = %d\n", x);
  printf("y = %d\n", y);
}

Bu sorunu elimine etmek için makroyu aşağıdaki gibi tanımlayabiliriz.

#include <stdio.h>

#define swap(a, b) do {int temp = a; a = b; b = temp;} while(0)

int main()
{
  int x = 10;
  int y = 45;

  if (x > y)
    do {int temp = x; x = y; y = temp;} while(0);
  else
    ++x;
  
  printf("x = %d\n", x);
  printf("y = %d\n", y);
}

-----------------------------------------------------------------------------------------

#define önişlemci komutunun kullanımları

#define PUBLIC (Önişlemci program kodda PUBLIC yazısını gördüğünde silecek. PUBLIC'i kod içinde bir anahtar sözcük gibi kullanacağız ama derleyici bunu görmeyecek)
#define SIZE 100 (Basit makrolar, özellikle sembolik sabitler. Burada bir isim var, bu isim basit bir yer değiştirme işlemine tabi tutuluyor.)
#define sumsquare(x, y) ((x) * (x) + (y) * (y))

-----------------------------------------------------------------------------------------

Koşullu Derleme Komutları - Conditional Compiling

Önişlemci programı, önişlemci zamanında her C, C++ programında gördüğü kodun tamamını derleyiciye vermiyor, bir kısmını veriyor.
Koşullu derleme komutlarını kullanarak önişlemciye, derleyiciden önce önişleme zamanında derleyiciye hangi kodu versin, vermesin amacıyla çalıştırıyoruz.
Önişlemci karşılaştığı kodların bir kısmını derleyiciye veriyor, bir kısmını veriyor.

Nasıl derleyicinin if, else if merdiveni, sadece doğru olan if deyimi, hem doğru hem yanlış if deyimleri varsa, önişlemci komutlarıyla önişlemci program için böyle bir yapı oluşturabiliyoruz.

Neden bunu yapıyoruz?

Derleyiciye, önişlemci programı kullanarak, derleyicinin farklı farklı kodları görmesini sağlamamızın büyük bir nedeni var.
Bir de durumdan duruma değişen nedenleri var.

1 - Donanıma bağlı olarak derleyicinin farklı kodların derlemesi.

Mesela bir proje var, sistem programı, PIG işlemcisinin 16/32 serisi kullanılıyor. 
Bazı kodlar PIG 16 ve PIG 32 için de aynı. Ama bazı kodlar işlemcinin, donanımın ne olduğuna bağlı olarak derleyici ayrı kodları görmek zorunda.
Böyle bir durumda koşullu derleme komutlarıyla eğer bu derleme işlemi PIG 16 için yapılıyorsa, derleyici bu kodu görsün, PIG 32yse derleyici bu kodu görsün.

2 - İşletim sistemine bağlı olarak derleyicinin farklı kodların derlenmesi.

Mesela aynı kaynak dosya, Windows, Linux, iOS için de derlenecek fakat bazı yerlerde kodlar Windows'a özel, Linux'a özel veya iOS'a özel kodların kullanılması gerekiyor.

3 - Derleyiciye bağlı olarak derleyicinin farklı kodları derlemesi

Mesela aynı kod, hem ARM, hem Clang, hem de GCC derleyicilerinde derlenecek. 
Ama biz derleyicinin eklentilerini kullanılıyoruz. Bu durumda kod tek, önişlemci programı koşullu derleme komutlarıyla derleyiciye göre görmesi gereken kodları veriyor.

4 - Programlama diline bağlı olarak derleyicinin farklı kodları derlemesi.

C ve C++ dilleri. Aynı kaynak dosya C'de de kullanılacak, C++ dilinde de kullanılacak.
C derleyicisinin görmesi gereken yerler farkı, C++ dillerinin görmesi gereken yerler farklı.

5 - Versiyona bağlı olarak derleyicinin farklı kodları derlemesi.

Mesela programın 1.1 sürümü, 1.2 sürümü var. Derleme işlemi duruma göre 1.1 sürümü için veya 1.2 sürümü için yapılacak.
Bunu ön işlemci programın koşullu derleme komutlarıyla yapabiliyoruz.

6 - Lokazisyona bağlı olarak derleyicinin farklı kodları derlemesi.

Aynı program Kazakistana, Afganistana da satılıyor olabilir ama bazı yerlerde ülkeye göre veya dile göre kaynak kodun farklı olması gerekiyor. 
Koşullu derleme komutlarıyla biz istediğimiz gibi derleyebiliyoruz.

Örnekleri daha da çoğaltmak mümkün fakat bunların en önemlisi hemen her C programında her kullanılan bir amaç, tema.

C ve C++ gibi dillerde programcı bir iş yaptırmak üzere bir kod yazıyor. Bu kod derlendiğinde, çalıştırıldığında programın amacı neyse o işi gerçekleştiriyor.
Fakat şöyle bir problem var, kodlama hataları.

Bu tarz dillerde kodlama hatası yapma riski çok yüksek. En ufak bir hata yapıldığında, debug ederken fark etmeyebiliriz.
Örnek fonksiyonlar

void func(int x)
{
  int y;
  ////
  y /= x;
}

Eğer x'in değeri 0 olursa, tanımsız davranış olur.

Peki biz kodu yazarken, programın kullanılmasıyla ilgili değil, yazılmasıyla ilgil, 
bu durumu unuttuk ve func'ı değeri 0 olan bir ifadeyle çağırdık.

int main()
{
  int x = 0;
  func(x);
}

-----------------------------------------------------------------------------------------

//Eğer bir kodlama hatası söz konusu ise, bu kod çalışsın. Yani burada amaç kodlama hatasını bulmak. Fonksiyona 0 gönderilmesi gibi.
//Amacı işi gerçekleştirmek değil de, programcının kendi kodlama hatalarını yakalamak için koda eklenen kodlara assertion deniliyor. Doğrulama kodu.
//Runtime'da eğer bir kodlama hatası varsa, bu assertion koduna takılacak ve ekrana hatanın ne olduğuyla alakalı bir şey yazdıracak ve hatayı bulabileceğiz.

//Debug sürecinde bu kodları derleyicinin görmesi gerekiyor ama debug süreci bitti, bu amaçla yazılmış tüm kodların derleyici tarafından görünmemesi gerekiyor.
//Eğer bunlar da kaynak kodda kalırsa ve müşteriye gidecek sürümde bu kodlar da derlenirse, kaynak kod büyüyecek, program daha yavaş çalışacak. 
//Koşullu derleme komutlarıyla biz önişlemciye "Biz şimdi debug için derleme yapıyoruz" diyebiliyoruz.

#include <stdio.h>
#include <stdlib.h>

void func(int x)
{
  if (x == 0){
    printf("%s kaynak dosyasinin %d. satirinda %s fonksiyonu icinde sifira bolme hatasi!\n",
    __FILE__, __LINE__, __func__);
    abort();
  }

  int y;
  y /= x;
}

int main()
{
  int a = 0;
  func(a);
}

-----------------------------------------------------------------------------------------

Koşullu derleme nasıl yapılır?

Önişlemci komutlarının bir kısmı bu iş için.

#if
#endif
#else
#elif
#ifdef
#ifndef

Böyle ifadelere preprocessor expression deniliyor. Derleyicinin ifade anlayışı ile önişlemcinin ifade anlayışı farklı.

preprocessor expression
tam sayı türlerinden sabit ifadesi olmak zorunda
gerçek sayı ifadesi olamaz

#define SIZE 100

#if SIZE > 100
    typedef int Word;
    Word a[10];
#endif

---------------------------------

Sadece doğru kısmı olan if komutu

#define SIZE 100

//Derleyici önişlemci zamanında, bu kodun doğru olup olmamasına göre bu kodu ya görecek, ya da görmeyecek.
//Burada önişlemci komutları da olabilir. Eğer bu bloğun içine girerse önişlemci program, nutility.h başlık dosyası da dahil edilecek.

#if SIZE > 10
    #include "nutility.h"
    typedef int Word;
    Word a[10];
#endif

---------------------------------

Else kısmı olan if komutu

#define CNT 100

#if CNT > 1000
    #include "nutility.h"
    typedef int Word;
    Word a[10];
#else
    #include "dogukan.h"
    typedef unsigned int Word;
    Word a[20];
#endif

---------------------------------

else if merdiveni

#define CNT 100

#if CNT > 1000
    #include "nutility.h"
    typedef int Word;
    Word a[10];
#elif CNT == 10
    #include "dogukan.h"
    typedef unsigned int Word;
    Word b[20];
#elif CNT != 100
    #include "dogukan.h"
    typedef unsigned int Word;
    Word b[20];
#else
    #include "dogukan.h"
    typedef unsigned int Word;
    Word b[20];
#endif

---------------------------------

Koşullu derleme işlemini ve kod seçimini daha kolay hale getirmek için bu şekilde ifadeler kullanabileceğimiz gibi bir operatörü de kullanabiliyoruz.

Eğer if önişlemci komutu yerine, ifdef komutunu kullanırsak (ifdef - ifdefined), buraya bir isim yazarsak mesela DOGUKAN, bu şu anlama geliyor.

Bu makro tanımlıysa, ilgili bloğa girecek, tanımlı değilse yanlış kısmına girecek.

#ifdef DOGUKAN
  #include "nutility.h"
  typedef int Degisken;
  Degisken a[10];
#else
  #include "dogukan.h"
  typedef unsigned int Degisken;
  Degisken b[10];
#endif

---------------------------------

Örnek olarak, kaynak kodumuzun Linux ortamı için derlenmesini istiyoruz. 
Aşağıdaki gibi bir önişlemci komutuyla, linux için derlenmesini istediğimizde #define LINUX önişlemci komutunu yazmamız yeterli olacak.

#define LINUX

#ifdef LINUX
    typedef int Word;
#endif

---------------------------------

ifdef komutunun da else kısmı olabilir, sonuçta bu da bir if.

#ifdef LINUX
    typedef int Word;
#else
    typedef long Word;
#endif

---------------------------------

ifdef komutunun tersi de ifndef. 
ifndef komutundan sonra yazdığımız makro tanımlı değilse bu bloğun içine gir anlamında.

#ifndef DOGUKAN
  typedef int DegiskenInt;
  DegiskenInt arr[10];
#endif

---------------------------------

#ifndef DOGUKAN
    enum Colors {Blue, Red, Black, White};
#else
    enum Colors {White, Black, Yellow, Green};
#endif

---------------------------------

#if     -> Bu koşul doğruya if'in içine girecek.
#ifdef  -> Bu makro tanımlıysa bu if'in içine girecek.
#ifndef -> Bu makro tanımlı değilse bu if'in içine girecek.

#if ifadelerinin sabit ifadesi olması gerekiyor.

Yani aşağıdaki gibi bir kullanım sentaks hatasıdır.

#define PRC 3.78242

#if PRC > 1.5
#endif

1 - Tam sayı ifadesi olmak zorundadır
2 - Karşılaştırma operatörleri
3 - Lojik operatörler
4 - Aritmetik operatörler
5 - Bitsel operatörler

---------------------------------

Diyelim ki, belirli kodlar para biriminin ne olduğuna bağlı olarak değişecek. Farklı para birimleri için farklı kodlar kullanılacak.

#define EUR 0
#define USD 1
#define GBP 2
#define JPY 3

#define CURRENCY GBP

#if CURRENCY == EUR
const char* gp = "EUR";
#else
	#if CURRENCY == USD
const char* gp = "USD";
#else
	#if CURRENCY == GBP
const char* gp = "GBP";
#else
	#if CURRENCY == JPY
const char* gp = "JPY";
#endif
#endif
#endif
#endif

---------------------------------

#elif neyi farkettiriyor? else if merdiveni 

Yukarıdaki gibi bir else if merdiveni oluşturursak, her if için ayrı bir endif yazmamız gerekir.

Ama #else yerine #elif kullanırsak, tek bir endif ile yapmış olacağız.

#if CURRENCY == EUR
	const char* gp = "EUR";
#elif CURRENCY == USD
	const char* gp = "USD";
#elif CURRENCY == GBP
	const char* gp = "GBP";
#elif CURRENCY == JPY
	const char* gp = "JPY";
#endif

---------------------------------

//DOGUKAN makrosu ve YAZAR makrosu tanımlı ise

#ifdef DOGUKAN
  #ifdef YAZAR
  #endif
#endif


defined önişlemci operatörü

defined DOGUKAN -> Önişlemci zamanında true ya da false değerini üretiyor.
Eğer DOGUKAN makrosu tanımlıysa true değer, tanımlı değilse false değer üretiyor.

Yani aslında bu iki kod da aynı.

#ifdef DOGUKAN
    typedef int Word;
#endif

#if defined DOGUKAN
    typedef int Word;
#endif

--------------------------------

Bu iki kod da aynı.

#ifndef DOGUKAN
    typedef int Word;
#endif

#if !defined DOGUKAN
    typedef int Word;
#endif


--------------------------------

#define DOGUKAN
#define YAZAR

#if defined DOGUKAN && defined YAZAR
    int val = 0;
#endif

--------------------------------

C dilinde bir başlık dosyayı bir kod dosyası tarafından birden fazla kez include edilmemelidir.

Bu yüzden biz başlık dosyalarını oluştururken, birden fazla kez include edilmesini engelleyecek önlem almamız gerekiyor.

Multiple Inclusion Guard
Çoklu Dahil Etmeye Karşı Koruma

Peki birden fazla kez include edersek ne olur?

Öyle bildirimler var ki, ikinci kez derleyici gördüğünde sentaks hatası oluşturuyor.

int foo(int);
int foo(int);

Bu geçerli bir bildirim.

struct Data {
  int x, y, z;
};

struct Data {
  int x, y, z;
};

Fakat bu geçerli bir bildirim değil. Sentaks hatası.

Böyle bildirimler genellikle başlık dosyasında olacak. Bu bildirim nutility.h başlık dosyasında olsun.
Ama biz bir nedenden dolayı bu başlık dosyasını iki kez include edersek, 
önişlemci program aşağıdaki komutları yürüttüğünde kaynak koda bu kodlar yapıştırılacak ve sentaks hatası olacak.

#include "nutility.h"
#include "nutility.h"

struct Data {
  int x, y, z;
};

struct Data {
  int x, y, z;
};

--------------------------------

kodeks.h başlık dosyasında aşağıdaki include komutu mevcut.

#include "nutility.h"

codex.h başlık dosyasında aşağıdaki include komutu mevcut.

#include "nutility.h"

Kaynak dosyada ise aşağıdaki başlık dosyalarını include edip, derlediğimiz zaman sentaks hatası olacak.
Çünkü bu başlık dosyalarındaki bildirimler iki kez yapıştırılmış oldu.

Öyle bir şey yapmalıyız ki, bu başlık dosyalarının birden fazla kez include edilmesini engelleyelim.

nutility.h başlık dosyasına aşağıdaki gibi bir koşullu derleme komutu ekliyoruz.

#ifndef NUTILITY_H
#define NUTILITY_H

struct Data {
  int x, y, z;
};

#endif

#ifndef NUTILITY_H // Eğer bu makro tanımlı değilse, bu bloğa girecek. (başlık dosyasının ismi yazılıyor genellikle, okuma kolaylığı açısından)
#define NUTILITY_H // Makro tanımlı değilse, tanımlıyoruz. 

Şimdi aslında burada olan, önişlemci program bu koşullu derleme komutunun içine ilk kez girdiğinde, bu makro tanımlı olmadığı için, içine girer girmemz bu makroyu tanımlayacak.
İçine ikinci kez girdiğinde, bu makro artık tanımlı olduğundan dolayı ikinci kez içine girmeyecek.

Burada kullanılan idiomatik yapıya Multiple Inclusion Guard deniliyor.

Bütün başlık dosyalarımızı, dilin bir kuralı olmasa da, böyle bir koruma altına almamız gerekiyor. 

--------------------------------------------------------------------------------

Multiple Inclusion Guard

Konvensiyon bu şekilde olabilir.

#ifndef KODEKS_INCLUDED
#define KODEKS_INCLUDED
//
//
//
#endif

defined operatörü ile bir kullanım da mevcut. Anlam olarak aynı şey.

#if !defined KODEKS_INCLUDED
#define KODEKS_INCLUDED
//
//
//
#endif

--------------------------------------------------------------------------------

Bu standart olan bir çözüm. Derleyicilerin bir çoğu bunun standart olmayan bir şekilde, başka bir önişlemci komutuyla da yapılmasını sağlıyorlar.
Bu bir standart değil.

#pragma once

ifdef ve ifndef'i hiç kullanmıyoruz. sadece bu önişlemci komutunu kullanıyoruz.

--------------------------------------------------------------------------------

#undef önişlemci komutu bir makronun tanımını ortadan kaldırıyor.

#undef SIZE

Önişlemci program bu undef komutunu gördüğünde, daha önce tanımlanmış olsa dahi, artık SIZE makrosunu tanımsız kabul edecek.

undef kullanma nedenleri

Bir makronun farklı iki şekilde define edilmesi.

Önişlemci program, asla bir makronun iki farklı şekilde define edildiğini görmemeli. 
Bu bir tanımsız davranıştır.

#define DOGUKAN 100
#define DOGUKAN 400

Mesela birden fazla başlık dosyasını include ediyoruz. Aşağıdaki gibi.

#include "kodeks.h"
#include "codex.h"
#include "dogukan.h"

#define DOGUKAN 1000

include ettiğimiz dosyalardan birinden böyle bir makronun tanımı gelirse, kod tanımsız davranış olacak.
makronun redefinition olmasını engellememiz gerekiyor.

#include "kodeks.h"
#include "codex.h"
#include "dogukan.h"

#undef DOGUKAN
#define DOGUKAN 1000

Artık tanımsız davranış olmayacak. Makro tekrar tanımlanmış olmayacak. 

--------------------------------------------------------------------------------

Blok önişlemcinin bildiği bir kavram değil. Blok derleyicinin bildiği bir kavram. 

void func()
{
    #define SIZE 1000
}

Önişlemci blok falan bilmez. Yukarıdaki durumda, komutun bulunduğu yerden başlayarak SIZE gördüğü yerleri 1000 sabitiyle değiştirecektir.

Peki biz bu makronun, yukarıdaki fonksiyonun ana bloğu içerisinde etkili olmasını istiyorsak, aşağıdaki gibi yapabiliriz.

void func()
{
    #define SIZE 1000

    #undef SIZE
}

Normalde makrolar derleyicinin gördüğü isimler olmadığı için bir scope kavramı söz konusu değil.
Ama bu şekilde define ve undef komutlarıyla kullandığımızda makroya bir scope kavramı kazandırmış oluyoruz.

Ayrıca bu idiomatik yapı fonksiyonel makrolar için de geçerlidir.

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#undef MAX

--------------------------------------------------------------------------------

Bazen de undef komutunun kullanımı koşullu derleme komutlarının yönünü, koşulunu değiştirmek için kullanılabilir.

#define DOGUKAN

#undef DOGUKAN

#ifdef DOGUKAN
  #define GUITAR 1
  typedef int Word;
#endif

--------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
#if MAX > 0
    typedef unsigned char Byte;
#endif
}

Yukarıdaki kodda, MAX makrosu tanımlı değil fakat if'in ifadesi içinde kullanılmış.
if içinde kullanılan ifadelerin tanımlanmış olma zorunluluğu yok.
Derleyici bunu görmüyor.


#include <stdio.h>

int main()
{
#if MAX > -1
    typedef unsigned char Byte;
#endif
}

Ama şimdi derleyici bunu görüyor. Bir if ifadesi içinde, tanımlanmamış bir makro kullanılırsa, 
sentaks hatası oluşmuyor, onun değerini 0 olarak alıyor. 

--------------------------------------------------------------------------------

predefined symbolic constants
ön tanımlı sembolik sabitler

#include <stdio.h>

int main()
{
  printf("%d", __LINE__);
}

Biz herhangi bir başlık dosyası eklemedik, ona rağmen bir sentaks hatası oluşmadı.
Öyle makrolar var ki, bunların bir define komutu yok. Dilin kuralı gereği önişlemci program bunları bir yer değiştirme işlemine tabi tutuyor.
Dil tarafından önceden tanımlandığı kabul edilen makrolara predefined symbolic constants deniliyor.

İki alt tire ile başlayıp iki alt tire ile biterler.

__LINE__
__FILE__
__DATE__
__TIME__
__STDC__

*/