/* 

Ders17

Fonksiyon bildirimleriyle derleyiciye bir fonksiyon hakkında bilgi veriyoruz.

Örnek

int foo(double, double);

Derleyici böyle bir bildirim gördüğünde, foo işlevinin geri dönüş değeri int, iki tane double türünden parametreye sahip olduğunu anlıyor.
Böylece bizim için gerekli kontrolleri yapıyor, yanlış bir kod yazmamız durumunda duruma göre sentaks hatası veya uyarı mesajı veriyor.
Bir de fonksiyona giriş ve fonksiyondan çıkış kodlarını üretiyor.

Bizim dışarıya hizmet verme iddiasında olan bir modül oluşturmamız demek aslında iki tane dosya oluşturmamız demek.

Bir tanesi kod dosyası, diğeri başlık dosyası.

Kod doyasında global değişkenlerin, fonksiyonların tanımları var.
Ama başlık dosyasında geleneksel olarak .h uzantısında, bu modülden hizmet alacak diğer kaynak dosyaları, onların derlenebilmesi için, onların kullandığı isimlerin burada bildirimleri var.

dogukan.c kaynak dosyasını yazarken, bu modülden hizmet alacaksam, ön işlemci programının #include komutuyla buradaki bildirimleri include komutunun olduğu yere yapıştırmış olacağız.
Böyle bizim kullandığımız bir ismin ne anlama geldiğini, derleyici bu başlık dosyasına gelen bildirimlerden anlayacak.

Kaynak dosyalarda tanımladığımız bütün varlıklar, diğer kaynak dosyaların ismiyle kullanımına açık değil.
Sadece bu modülün çağıracağı fonksiyonlar, yani diğer modüllerden çağrılması istenmeyen, onların bilmesini tercih etmediğimiz isimlere ilişkin, bunların dışarıdan kullanılması için özel bir anahtar kullanıyoruz.

static anahtar sözcüğü

Bir kaynak dosyada aşağıdaki gibi bir fonksiyon bildirimi veya tanımı, bu fonksiyon sadece dogukan.c dosyasında çağrılacak, diğer kaynak dosyalarından çağrılması istenilmemiş.

//dogukan.c

static int foo(void)
{

}

Diğer programlama dillerinde private anahtar sözcüğü gibi.
Böyle fonksiyonlara external functions deniliyor.
External Linkage Functions

Bir kaynak dosyada iki ayrı tipde fonksiyon var.

Bir tanesi, bir kaynak dosyada tanımlanmış ama dışarıya da açılmış. Default durum. Varsayılan.

İkincisi, bir kaynak dosyada tanımlanmış fakat sadece bu kaynak dosyanın kullanımına sunulmuş.

int foo(void)
{

}

static int func(void)
{

}

---------------------------------------------------------------------------

static anahtar sözcüğü overload edilmiştir yani iki ayrı farklı kullanımı vardır.

Biri bu anlattığımız bağlamda kullanımı.

Global değişkenler için de aynı şey geçerli.

#include <stdio.h>

int g = 10; //global bir değişken tanımladık, diğer kaynak dosyalardan da bu değişken, ismiyle kullanılsın.

int main()
{

}

Global değişkenin tanımında static anahtar sözcüğü olursa, bu global değişkeni sadece bu kaynak dosya kullanacak. Diğer kaynak dosyaları bu isimle bu değişkeni kullanamayacak.

---------------------------------------------------------------------------

Yukarıdaki static anahtar sözcüğü ile buradaki static anahtar sözcüğünün yani foo fonksiyonunun tanımındaki static ile hiçbir alakası yok.
Maalesef, static anahtar sözcüğüne farklı iki anlam yüklenmiş.

static int g = 10;

static int func(void)
{

}

void foo()
{
    static int a; // Buradaki static anahtar sözcüğü a isimli yerel değişkenin, otomatik ömürlü olmadığını, static ömürlü olduğunu söylüyor.
}

---------------------------------------------------------------------------

https://en.cppreference.com/w/c/header

Standart kütüphaneyi, lojik bir izolasyon sağlamak için modüllere ayırmışlar.
Standart kütüphanenin modüllerinin de standart başlık dosyaları var.

Örnek olarak,

stdio.h
ctype.h
stdlib.h
math.h
assert.h
locale.h
string.h
stdint.h
stdbool.h
stddef.h
limits.h

C11 ile gelen başlık dosyaları henüz yaygın kullanımda değil.
C89 ve C99'u istemesek de ezberlememiz lazım. Çok fazla kullanacağımızdan dolayı.

---------------------------------------------------------------------------

C dilinde uzun yıllar boyunca geçerliliğini korumuş, C99 standartlarıyla geçersiz hale gelen fakat derleyicilerinin hemen hepsinin geçerli kabul ettiği bir durum var.

C++ dili söz konusu olduğunda, C++ dilinde zaten kural bu şekilde.

C++'da aşağıdaki programda, derleyici func ismini arayacak ve bulamayacağı için hata mesajı verecek.

int main()
{
    func(10);
}

Ama C dilinde, aynı kodu derlediğimizde herhangi bir sentaks hatası vermiyor.
Aşağıdaki örnekteki gibi, eğer bir isim fonksiyon çağrı operatörünün operandı olmuşsa, derleyici bu ismi arayıp bulamayınca,

int main()
{
    func(10);
}

Bu o zaman dilin kurallarına göre, başka bir modülde, başka bir kaynak dosyada tanımlanmış, 
geri dönüş değeri türü int olan, ismi func olan ve parametrik yapısı hakkında bilgi verilmeyen bir fonksiyon kabul ediyor.

Default olarak böyle bir fonksiyonu var kabul ediyor. Böyle fonksiyonlara default function declaration.

Derleyici bu fonksiyonun geri dönüş değer tipi int, parametrik yapısının da bilinmediğini varsayıyor, buna göre kod üretiyor.
Asla asla asla, bildirimini veya tanımını derleyicinin görmediği bir fonksiyona çağrı yapmamalıyız.

Eskiden gelen C dilinin kurallarından biri. Geçmişte yazılan kodların, günümüzde tekrar derlendiğinde sentaks hatası oluşmaması için.

Derleyicilerin çoğu bir sentaks hatası vermese de, bir uyarı mesajı verecektir.

warning : 'func' undefined, assuming extern returning int. 

int func(); // bu şekilde.

int main()
{
    func(10); // bu şekilde çağrı yaptığımızda, üst satırdaki fonksiyon bildirimi yapmış oluyoruz aslında.
}

---------------------------------------------------------------------------

Önişlemci programı ve önişlemci komutları

Preprocessor - Bu bir text işleyen program.

Derleyicinin giriş modülü gibi ayrı bir program. Biz derleyici çalıştırdığımız derleyici ilk olarak bu modülü çalıştırıyor.
Önişlemci program kendi komutlarını yürütüyor.
Önişlemci programın ayrı bir sentaksı var, kuralları var.

Önişlemci komutları # karakteri ile başlayan satırlar. Bunlar derleyiciye değil önişlemci programa gönderiliyor.

Preprocessor directives - önişlemci komutları

# (null directive)
#include
#define
#undef
#if
#elif
#else
#endif
#ifdef
#ifndef
#line
#error
#pragma

Derleyicinin anahtar sözcükleriyle, ön işlemcinin sözcükleriyle karıştırmamamız lazım.

Önişlemci programı, derleyiciden önce çalışıyor.
Önişlemci programın çıktısı, derleyici programın girdisi.

GCC, CLang, Microsoft derleyicisinde, bunların switchleriyle önişlemci programın çıktısı olan dosyayı da ürettebiliyoruz.

Önişlemci program çalıştırılmış, bütün kaynak dosyada bulunan önişlemci komutlarını yürütmüş, sıra derleyiciye gelmiş.
Önişlemcinin çıktısı, derleyicinin girdisi.

Önişlemcinin girdisi -> Source File
Derleyicinin girdisi -> Translation Unit (derleyicinin gördüğü kod)

---------------------------------------------------------------------------

Başlık dosyalarında neler var, neler olmalı?

- Fonksiyon Bildirimleri (hizmet alacak kodların, ihtiyaç duyduğu fonksiyon bildirimleri)
- Global Değişken Bildirimleri
- Önişlemci Komutları
    - Macro Tanımları
- Tür Bildirimleri ve Tanımları

---------------------------------------------------------------------------

#include önişlemci komutu

Ek bir bilgi: Önişlemci komutunu yorum satırına alabiliriz.

Bu komut önişlemci programa bir ismi verilen dosyanın içindeki bildirimlerin komutun yazıldığı yere yapıştırıldığı talimatı.
Bu komuta kabaca bakarsak, kopyala yapıştır komutu.

#include <stdio.h> -> Önişlemci program, stdio.h dosyasını bul, onun içindeki bildirimleri bu komutun bulunduğu yere kopyala.

Çok extrem senaryolar dışında, bu komut her zaman başlık dosyalarının içindeki bildirimleri kaynak dosyamıza eklemek için kullanılır.
Asla kod dosyasını, include komutuyla dahil etmeye çalışmamamız lazım.

Hiçbir önişlemci komutunun sonunda ; yok. 

#inlude <stdio.h>; -> noktalı virgülün önişlemci komutuyla hiçbir alakası yok.

Bu komutun sentaksında iki ayrı kullanım biçimi var.

1. kullanım biçimi, dosya isminin açısal parantez içiminde yazılması
2. kullanım biçimi, dosya isminin çift tırnak içiminde yazılması

#include <stdio.h> 
#include "nutiliy.h"

Her ikisinin de amaç, bu dosya içeriklerinin komutu yazdığım yere kopyalanması.

#include <stdio.h> 
#include "nutiliy.h"

Açısal parantez içinde yazılmış başlık dosyalarının önceden belirlenmiş varsayılan olarak bir dizinde bulunması gerekiyor.
Default Directory

Çift tırnak içinde yazdığımızda bu durumda, önişlemci programı bu ismi actual directory denilen dizinde arıyor.
Fiilen kaynak dosyamızı yerleştirdiğimiz yer.

İkinci önemli fark ise, anlam olarak. 

Açısal parantezle kullanımda anlatmak istediğimiz şey, bu dosyayı bizim oluşturmadığımız bilgisi.
Bu dosya bana derleyici tarafından veriliyor.
Bu dosyalar ya standart c başlıkları.
Açısal parantezle kullanımda derleyicini bu başlık dosyasını include dizininde arayacak.

Ama bazen de, derleyicinin verdiği fakat standart olmayan başlık dosyaları var, bunların include edilmesinde açısal parantez kullanıyoruz.
Doğrudan derleyicinin bize verdiği başlık dosyaları.

#include <windows.h>
#include <conio.h>

Özetle, 

Açısal parantezle kullanımda, 
standart başlık dosyalarının isimlerini yazmamız lazım. 
ya da derleyici tarafından bize verilmiş, sağlanmış dosyaların isimlerini yazmamız lazım.

Bizim oluşturduğumuz veya 3. parti başka biri tarafından oluşturulmuş başlık dosyalarını çift tırnak ile yazmamız lazım.

---------------------------------------------------------------------------

#include <stdio.h>

Önişlemci programı, yukarıdaki önişlemci komutunu görüdüğünde ne yapıyor?

Ayrıca başlık dosyalarında yalnızca fonksiyon bildirimi yok, önişlemci komutları da var. Önişlemci programı, bu önişlemci komutlarını da yürütüyor.

Önişlemci programın komutlarından bir gruba, conditional compiling ismi veriliyor. Koşullu derleme. Bir komut grubunun ismi.

#if
#else
#elif
#ifdef
#ifndef

Koşullu derleme komutlarıyla, önişlemci program için bir kod bloğu oluşturuyoruz.

#ifdef DOGUKAN
    //bildirimler
    //ön işlemci komutları
#endif

Önişlemci program, yukarıdaki örnekteki gibi bir koşullu derleme bloğuyla karşılaşırsa, aynı derleyici gibi, koşulun doğru olup olmadığını sınayacak. 
Derleyiciyle herhangi bir alakası yok, bu sınama önişlemci programın zamanında oluyor.

#ifdef DOGUKAN -> bu koşul doğruysa, bloğa girecek. bu koşul yanlışsa, bunun içine hiç girmeyecek

#if 1 -> buradaki ifade, önişlemci zamanında non zero bir değer ise, burası doğru olacak. 

#endif

#if 0 -> buradaki ifade 0 olduğundan,buraya hiç girilmiyor.

#endif

---------------------------------------------------------------------------

Eğer herhangi bir kod yukarıdaki gibi bir koşullu derleme bloğu içine alınmamışsa, önişlemci bu kodu olduğu gibi derleyiciye veriyor.
Yani önişlemci komutunun bulunduğu yere bu kodu yapıştırıyor.

Eğer böyle bir kod, bir koşullu derleme bloğu içine alınmışsa, iki ihtimal var.

Koşul doğru, önişlemci program bu bloğa girecek bu kodu derleyiciye verecek.
Koşul yanlış, önişlemci program bu bloğa girmeyecek bu kodu derleyiciye vermeyecek.

Koşullu derleme komutlarıyla, önişlemci programın ele aldığı dosya içerisinde nereye girip nereye girmemesi gerektiğini belirleyebiliriz.

#ifdef DOGUKAN
    void func(int);
#else
    void func(int, int); //önişlemci program, bu kod bloğu ile karşılaştığında buraya girecek.
#endif

Önişlemci programcı, üstünden geçtiği başlık dosyası içindeki;
Bildirimleri derleyiciye veriyor.
Önişlemci komutlarını da yürütüyor.
Hatta include komutuyla include edilen başlık dosyalarının içinde de include komutu olabiliyor tipik olarak.

---------------------------------------------------------------------------

#include "dogukan.h"

Önişlemci program dogukan.h dosyasının içine girecek ve normalde oradaki bildirimleri bu komutun bulunduğu yere yapıştıracak.
Ama bu başlık dosyasının içinde de, örnek olarak tekrar bir #include "yazar.h" önişlemci komutu varsa, bu kez önişlemci program bu dosyanın içine girecek.

Bu include derinliği, bazen 6-7 kez olabiliyor.

---------------------------------------------------------------------------

Örnek olarak, nutiliy.h ve dogukan.h isimli başlık dosyalarını oluşturduk.
nutility.h başlık dosyanının içinde dogukan.h başlık dosyasını include ettik.
dogukan.h başlık dosyasında func isimli bir fonksiyon bildirdik.
nutility.h başlık dosyasını programımıza include ettiğimizde, dogukan.h isimli başlık dosyasındaki bildirimlere de ulaşabiliyor olacağız.

#include "nutility.h"

int main()
{
    func(3, 5);
}

---------------------------------------------------------------------------

Başlık dosyalarının içindeki kodlar;

Doğrudan başlık dosyalarının içinde. Herhangi bir koşul falan yok.

Biri doğrudan başlık dosyasında kodların olması.

void func(int, int);

Diğeri de koşullu derleme. Önişlemci zamanında bu blogun içine girip girmeyeceğin, önişlemci zamanında bu koşulun doğru olup olmadığına bağlı.

#kosullu derleme blogu
    void func(int, int);
#endif

---------------------------------------------------------------------------
Koşullu derleme komutları

#if
#ifdef
#ifndef

#endif
---------------------------------------------------------------------------

#define önişlemci komutu

Bu komutla biz, önişlemci programa bir isim tanıtmış oluyoruz. Önişlemci programa belirli bir amaç için tanıtılmış isimlere macro terimi deniliyor.

Macro: C ve C++ dillerine özel bir terimdir. Önişlemci programa, ne amaçla olursa olsun #define ile tanımlanan isimlerdir.

#define DOGUKAN
#define max (a, b) a > b ? a : b)

Makroların farklı farklı kullanım alanları var. 

Makroların birinci kullanım biçimi:

#define önişlemci komutunu #define MAX 1000 şeklinde kullandığımızda, duruma göre aşağıdaki terimler kullanılıyor.

object-like macro (nesnel makro)
symbolic constant (sembolik sabit)
manifest constant (manifesto sabiti)

#define MAX 1000 -> Önişlemci, dosya içerisinde bu ismi bul. Bu ismin bulunduğu yere bu yazıyı yerleştir. Talimatını vermiş oluyoruz. MAX ismini bul, MAX isminin olduğu yerlere 1000 sabitini yerleştir.

Text editörlerindeki find and replace komutu gibi. Bul - Değiştir.

#define SIZE 100

int x = SIZE;

Yalnız bu işin yapılması için bazı koşulların oluşması gerekiyor. 

Bu yer değiştirme işleminin, komutun bulunduğu yerden daha aşağıdaki bir bölge için yapılıyor olması.
Case-sensitive değilse, büyük harf küçük harf duyarlı olarak yapılıyor bu yer değiştirme işlemi.
Karakter sabitleri içerisinde asla bir yer değiştirme yapılmayacak.

//Ekrana SIZE yazacak, 100 yazmayacak. Böyle bir kullanım mümkün değil.

#define SIZE 100

int main()
{
    printf("SIZE\n");
}

---------------------------------------------------------------------------

Diğer dikkat edilmesi gereken nokta ise, bu yer değiştirme işleminin bir yazı olarak yapılması.
Aşağıdaki örnekteki gibi, SIZE olan yere 100 + 50 yazısını koyacak. 

#include <stdio.h>

#define SIZE 100 + 50

int main()
{
    int x = SIZE * 5;

    printf("x = %d\n", x);
}

Ekran çıktısı: 350

--

#include <stdio.h>

#define SIZE (100 + 50)

int main()
{
    int x = SIZE * 5;

    printf("x = %d\n", x);
}

Ekran çıktısı: 750

---------------------------------------------------------------------------

#include <stdio.h>

#define ERROR_MSG "Bellek Yetersiz!"

int main()
{
    printf("%s", ERROR_MSG);
}

---------------------------------------------------------------------------

#define komutunu kullanırken bir alt satırı da komuta dahil etmek için satırın sonuna ters bölü karakterini ekleyebiliriz.

#include <stdio.h>

#define MAX 200 + 300 + 400 + \
500

int main()
{
    printf("%d", MAX);
}

---------------------------------------------------------------------------

Önişlemci komutlarının sonuna noktalı virgül atomu gelmemesi gerekiyor. 
Dilin kuralları bu şekilde, ama olur da yanlışlıkla noktalı virgül koyarsak, önişlemci bunu bir yazı olarak algılıyor.

Bu duruma göre sentaks hatası olabilir veya olmayabilir.

Sentaks hatası olmayan örnek program:

#include <stdio.h>

#define SIZE 100;

int main()
{
    int x;
    int y;

    x = SIZE; //Önişlemci programı buraya 100; yazısını koydu, var olan ; null statement oldu.
    y = x + 5;
}

---------------------------------------------------------------------------

Sentaks hatası olan örnek program:

#include <stdio.h>

#define SIZE 100;

int main()
{
    int x = 5;

    if (x == SIZE) // derleyicini burada if (x == 100;)
        ++x;
}

Ayrıca #define önişlemci komutuyla yazdığımız makroda, eğer aritmetik bir ifade var ise burada parantez kullanmak operatör önceliğini değiştirebilir.

---------------------------------------------------------------------------

Peki #define önişlemci komutu ne amaçla ve neden kullanılıyor?

Birden fazla kullanım biçimi var.

Birincisi sabitleri doğrudan kullanmak yerine onları isimlendirmek. define komutunun en sık kullanıldığı temalardan biri.

Kaynak kodumuzda bir değişken var ve bu değişkene bir değer atanmış.

int x;

x = 7232655;

Sabitler kaynak kodun kaçınılmaz öğeleri, ne anlama geldiğini ilk baktığımızda anlayamıyoruz.
Eğer biz bu sabiti kullanmak yerine bir isim kullansaydık ve bu isim bir macro ile define edilmiş olsaydı, anlamlı hale gelecekti.

Önemli bir konvensiyon bilgisi:

Tamamı büyük harfle yazılmış isimler, ALL CAPS isimler macrolara ayrılmıştır.
Hiçbir C programcısı, bir değişkenin ismine tamamı büyük harf bir isim vermez. 
Böylece kaynak koda bakan herkes, bu ismin bir macro olduğunu koda bakara anlayabilir.

#define NO_OF_BOOKS 2448

int main()
{
    int x = NO_OF_BOOKS;
}

Bu macrolar derleyici açısından bir isim yani identifier değil.

Tabiki bu yer değiştirme işleminin bir sabitle olması zorunluluğu da yok. Şöyle de olabilir;

#define BYTE unsigned char

int main()
{
    BYTE x = 150;
}

Bazı durumlarda bir macronun tanımında başka bir macro kullanılacak.

#define MAX 500
#define MIN 100
#define MEAN ((MAX + MIN) /2) 

int main()
{
    int x = MEAN;

    printf("%d", x);
}

---------------------------------------------------------------------------

Standart ve 3. parti kütüphanelerde macrolar

Bazı macroların kullanım nedeni doğrudan kodun okunmasını kolaylaştırmak.
Bazı macroların kullanım nedeni ise taşınabilirliği arttırmak.

int main()
{
    int x = 2147483647; //işaretli int türünden 4 bytelık bir alanda alabileceği en büyük değer.
}

Programcının burada bunu yazma nedeni, kullandığı algoritma gereği x'e taşıyabileceği en büyük değeri ilk değeri vermek veya atama yapmak
Kodun okunmasının zor olması bir yana, bu kodu başka bir derleyicide derlediğimiz ne olacak?

Bizim derleyicimizde int türü 2 byte. 2 bytelık int türü söz konusu olduğunda, bunun alabileceği en büyük değer 32767.

Dolayısıyla bu kodun aynı anlamı koruyabilmesi için, int türünün 2 byte olan bir sistemde derlendiğinde buradaki sabitin değiştirilmesi gerekiyor.
Bu da hata oluşma riski çok yüksek bir senaryo.

Bunun için limits.h başlık dosyasında tanımlanan bazı önemli macrolar var.

#define SHRT_MIN
#define SHRT_MAX
#define INT_MIN
#define INT_MAX

#include <stdio.h>
#include <limits.h>

int main()
{
    int x = INT_MAX;
}

Sonu max ile bitenler, ilgili türün alabileceği en büyük değerler.
Sonu min ile bitenler, ilgili türün alabileceği en küçük değerler.

Ama her derleyicinin limits.h başlık dosyası kendine göre oluşturulmuş.
Yani biz bu kodu int türünün 2 byte olduğu bir derleyicide derlersem, buraya 32767 yapıştırılacak.

Biz bu INT_MAX macrosunu kullandığımızda, hangi derleyicide çalıştırsak çalıştıralım, o derleyicinin limits.h başlık dosyasındaki işaretli int türünün en büyük değerini kullanacağız.

Hem kodun okunması kolaylaştı, hem de taşınabilirlik sağlandı.

Tam sayı değerlerinin en büyük değerleri alt tire ile tanımlanmış.

INT_MAX     Signed
UINT_MAX    Unsigned

INT_MIN

İşaretsiz tam sayı türleri için sadece MIN var. 

UCHAR_MAX
CHAR_MIN

limits.h taşınabilirlik sağladığı için önemli bir başlık dosyası.

---------------------------------------------------------------------------

Sadece bunlarla kullanımı kısıtlı değil. Standart kütüphane macroları belirli donanıma veya derleyiciye bağlı sabitler için de kullanıyor.

Bazı durumlarda bu macrolar numaralandırma amacıyla kullanılacak. Bazı durumlarda bu macrolar, fonksiyonlara argüman göndermek için kullanılıyor.

Bazı fonksiyonlar var, bunların parametresi int türden, ama bizden önceden seçilmiş sabitlerden birini istiyor.
Bunlar daha okunaklı olsunlar diye, macrolar tercih edilmiş.

int main()
{
    FILE* f;

    fseek(f, 0L, SEEK_SET);
}

Aşağıdaki kodu okuyan bir programcı, programı sonlandırmanın sebebinin başarısızlık olduğunu exit fonksiyonuna gönderilen argümandan anlıyor. 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    exit(EXIT_FAILURE);
}

Veya bu örnek;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char *p = setlocale(LC_ALL, LC_MAX);
}

---------------------------------------------------------------------------

Ayrıca tür bilgileri için de çok sık kullanılıyor.

C dilinde _Bool isminde bir tür var. 

stdbool.h başlık dosyanın içinde aşağıdaki gibi önişlemci komutuyla macro tanımlaması yapılmış.

#define bool	_Bool
#define true	1
#define false	0

#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool flag;

    flag = true;
    flag = false;
}

Aslında derleyicinin gördüğü kod bu;

#include <stdio.h>
#include <stdbool.h>

int main()
{
    _Bool flag;

    flag = 1;
    flag = 0;
}

---------------------------------------------------------------------------

define komutunun değişik bir kullanımı

#define PUBLIC

Bu durumda bu macro kod içerisinde kullanılırsa, önişlemci bu PUBLIC sözcüğünü koddan silecek.
Bir yazının kodda görünmesini istiyoruz ama derleyicinin görmesini istemiyoruz. Bu şekilde de bir kullanım mevcut.

#include <stdio.h>
#define PUBLIC

PUBLIC void func(int x)
{

}

Derleyicinin gördüğü;

void func(int x)
{

}

---------------------------------------------------------------------------

Ayrıca define önişlemci komutu gerçek sayı sabitlerinin yazımında da kullanılıyor.

Gerçek sayı sabitlerinin yazma hatasına karşı çok hassas oldukları için macro tanımlanabilir.

Örnek olarak pi sayısını tanımlarsak, yanlış yazma riskimiz olmaz. 
Okunabilirlik açısından da oldukça faydalı.

#define PI 3.1415926535

Veya kök 2 sabitini kullanacağız. 

#define SQUARE_2 1.414213562373

Matematikdeki, fizikdeki sabitleri doğrudan kullanmak faydalı olmayabilir. 
Bunları doğrudan değil de macrolar ile define edebiliriz.

Standart kütüphane doğrudan bu macrolara sahip değil fakat Linux sistemlerinde genişletişmiş bir C kütüphanesi var.
Önişlemciler bunları koşullu derleme komutlarıyla kullanımımıza sunuyor.

Örnek olarak math.h başlık dosyasının için aşağıdaki gibi bir satır var.

#ifdef _USE_MATH_DEFINES
    #include <corecrt_math_defines.h>
#endif

Eğer bu sabitleri kullanmak istersek, _USE_MATH_DEFINES makrosunu aşağıdaki define etmemiz gerekir.

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    double dval = M_SQRT1_2;
    printf("%.10f", dval);
}

---------------------------------------------------------------------------

Makroların diğer bir kullanım alanı, fonksiyonel macro diye geçiyor.

functional macro
function-like macro

Buradaki amaç, önişlemci programa bir yer değiştirme işlemi yaptırarak adeta bir fonksiyon çağrısı gibi kullanılacak bir macro oluşturmak.
İlk önce isim, ardından bir boşluk karakteri bile olmadan açılan kapanan parantez.
Bu parantezin için bir ya da birden fazla isim tanıtabiliyoruz. Macro parametresi diyebiliriz.
Kapanan parantezden sonra gelen yazı yer değiştirme listesi. 
Replacement list. Önişlemci programa, bu macronun karşılığında nasıl bir yer değiştirme işleminin yapılacağını anlatıyor.

#define MAX(a, b)  (a > b ? a : b)

Örnek Program

#include <stdio.h>
#define MAX(a, b)  (a > b ? a : b)

int main()
{
    int x = 10;
    int y = 20;

    ///code

    int max = MAX(x, y);
    Aslında yukarıdaki satırda, derleyicinin gördüğü bu: int max = (x > y ? x : y);
}

---------------------------------------------------------------------------

Böyle macroları tanımlarken operatör önceliğinden kaynaklanan hatalara önlem almak için yapılması gerekenler var.

Örnek Program

#include <stdio.h>
#define SQUARE(a)   a * a

int main()
{
    int x = 10;
    int y = SQUARE(x + 1); //Bu bir fonksyon olsaydı, fonksiyon 11 değeriyle çağrılacaktı. 121 olacaktı y'nin değeri. Ama şimdi aşağıdaki gibi bir durum oldu.
    // Önişlemci program yer değiştirme yaptığın için, int y = x + 1 * x + 1; şeklinde oldu. Bu ifadenin değeri 21 oldu.
}

Bunun çözümü ise, define tanımında ifademizi öncelik parantezine almak.

#include <stdio.h>
#define SQUARE(a)   (a) * (a)

int main()
{
    int x = 10;
    int y = SQUARE(x + 1);
    Şuan istediğimiz gibi oldu, int y = (x + 1) * (x + 1); şeklinde yorumlanacak.

}

Güvenli macro yazmak için, macro parametresinin yer değiştirme listesinde geçtiği her yerde parametreleri parantez içine almalıyız.
Tabi bu da yeterli değildir. Mesela aşağıdaki durum için.

#include <stdio.h>
#define SQUARE(a)   (a) * (a)

int main()
{
    int x = 5;
    int y = 100 / SQUARE(x); //Bu bir fonksiyon olsaydı, 100 / 25 = 4 şeklinde yorumlanacaktı. Ama burada yer değiştirme yapılınca aşağıdaki gibi yorumlanacak.
    // int y = 100 / (x) * (x); burada öncelik yönü soldan sağa, 100 / 5 = 25, 25 * 4 = 100 şeklinde yorumlanacak.
    
    printf("%d", y);
}

Ama fonksiyonel macro tanımının değiştirme listesinde dıştan parantez olsaydı, istediğimiz sonucu alacaktık.

#include <stdio.h>
#define SQUARE(a)   ((a) * (a))

int main()
{
    int x = 5;
    int y = 100 / SQUARE(x);
    //Bu şekilde yorumlanacak: int y = 100 / ((x) * (x)); 
    
    printf("%d", y);
}

---------------------------------------------------------------------------

Fonksiyonel macro tanımındaki her parametre değişkenini parantez içerisine alıyoruz. 

#include <stdio.h>

#define isleap(x) ((x) % 4 == 0 && ((x) % 100 != 0 || (x) % 400 == 0))

int main()
{
    int x;

    printf("Bir yil girin: ");
    scanf("%d", &x);

    if(isleap(x))
        printf("%d yili artik yil\n", x);
    else
        printf("%d yili artik yil degil \n", x);
}

Derleyicinin gördüğü: 

if(((x) % 4 == 0 && ((x) % 100 != 0 || (x) % 400 == 0)))

---------------------------------------------------------------------------

#define isupper(c) ((c) >= 'A' && (c) <= 'Z')
#define tolower(c) (((c) >= 'A' && (c) <= 'Z') ? (c) - 'A' + 'a' : (c))

---------------------------------------------------------------------------

#include <stdio.h>
#define square(x) ((x) * (x))

int main()
{
    int a = 9;

    int b = square(a++); //eğer square bir fonksiyon olsaydı, ilk önce a++ ifadesinin değeri hesaplanacaktı, ve fonksiyona argüman olarak 9 değeri gönderilecekti
    //Derleycinin gördüğü: int b = ((a++) * (a++));
    //Burada tanımsız davranış var. Yan etki noktası geçmeden, yan etkiye uğramış bir nesneyi tekrar kullandık.

    printf("b = %d\n", b);
    printf("a = %d\n", a);
}

---------------------------------------------------------------------------

Eğer macro parametresi, açılım listesinde birden kez tekrar ediyorsa macroyu kullananın buna çok dikkat etmesi gerekiyor.
Bu bir fonksiyon değil, macro.

#include <stdio.h>
#define square(x) ((x) * (x))

int func(int);

int main()
{
    int a = square(func(5)); //square bir fonksiyon olsaydı, ilk önce func fonksiyonu çağrılacaktı, func fonksiyonunun geri dönüş değeri square fonksiyonu çağrılacaktı.
    //fakat burada fonksiyonel macro tanımı olduğu için kodun anlamı tamamen değişiyor. 
    //int a = ((func(5)) * (func(5))) -> Önişlemci bu macroyu açtığında derleyicinin gördüğü kod bu olacak. 

}

---------------------------------------------------------------------------

SORU: Aşağıdaki programda, fonksiyon olaran square mi kullanılacak yoksa macro olan mı?
Cevap: macro. Önişlemci program derleyiciden önce çalıştığı için.

#include <stdio.h>

int square(int x)
{
    printf("Function square\n");
    return x * x;
}

#define square(x) ((x) * (x))

int main()
{
    int a = 10;
    int b = square(a);
}

---------------------------------------------------------------------------

SORU: Peki fonksiyon ve macro aynı isimdeyse, fonksiyonu tercih etmek için ne yapacağız?
Cevap: fonksiyon çağrısındaki fonksiyon ismini parantez içerisine alacağız. Böylelikle macro devreye girmeyecek çünkü isimden sonra açılan parantez değil, kapanan parantez var.

#include <stdio.h>

int square(int x)
{
    printf("Function square\n");
    return x * x;
}

#define square(x) ((x) * (x))

int main()
{
    int a = 10;
    int b = (square)(a);
}

---------------------------------------------------------------------------

Eğer aynı isimli macro ve fonksiyon varsa ve macro tanımını fonksiyon tanımından önce yaparsak, önişlemci program bu fonksiyon tanımını macronun argümanı olarak alacak ve sentaks hatası olacak.
Bu sorunu çözmenin iki yolu var. 

Birincisi macronun aşağıda tanımlanması.
Bunun gibi:

int square(int x)
{
    printf("Function square\n");
    return x * x;
}

#define square(x) ((x) * (x))

İkincisi ise fonksiyon tanımlama sentaksında fonksiyonun ismini parantez içine alınması.
Bunun gibi:

#define square(x) ((x) * (x))

int (square)(int x)
{
    printf("Function square\n");
    return x * x;
}

---------------------------------------------------------------------------

Peki neden fonksiyonel makro kullanıyoruz?

Fonksiyonları çoğu yerde kullanıyoruz ama bazı durumlarda fonksiyonların bir dezavantajı var.

Bur bir fonksiyon ve basit bir fonksiyon olduğunu düşünelim. One-liner
int func(int x)
{
    return x > 10 ? x * x : x / 10;
}

Biz bu fonksiyona bir çağrı yaptığımızda, derleyici bu fonksiyonun kodunu da görmüyorsa, sadece bildirimini görüyorsa, fonksiyona giriş ve çıkış kodunu üretece, linker içinde bir referans isim yazacak.
Buradaki işlem maliyeti düşük fakat fonksiyona giriş çıkış kodlarının maliyeti yüksek.
Bir de bu fonksiyon çok sık çağrılıyorsa, bu durumda verim açısından ciddi bir fark oluşuyor.

Kısacası kodu küçük fakat çok sık çağrılan fonksiyonlarda, aslında yapılan işlemlerin maliyeti çok düşük olmasına rağmen, 
bunu bir fonksiyon haline getirdiğimiz için, fonksiyona giriş fonksiyondan çıkış kodlarının da maliyetini ödüyoruz.

Dolayısıyla, fonksiyonel makroların kullanılmasındaki en temel fikirlerden biri verimi arttırmak. Özellikle sistem programlama, embedded progrmalama tarafında verim çok önemli.
İşte burada fonksiyona giriş çıkış kodlarının maliyetini ödememek için, bunu makro şeklinde ifade ediyoruz.

*/


