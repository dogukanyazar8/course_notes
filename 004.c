/* 

Ders4

-----------------------------------------------------------------------
BASIC TYPES
    Integer Types
    Floating Types
USER DEFINED TYPES
    Structures
    Unions
    Enumarations
-----------------------------------------------------------------------
INTEGER TYPES

1 Byte
char (Implementation Defined (Derleyici karar veriyor))                
signed char
unsigned char

2 Byte
short int
unsigned short int

2/4/8 Byte
int
unsigned int

4/8 Byte
long int
unsigned long int

8 Byte
long long int (C99)
unsigned long long int (C99)

1 Byte
_Bool (Unsigned Integer Types)

printf("Size of char: %zu\n", sizeof(char))

Compiler Extensions (Derleyici Eklentisi)

Derleyicilerin programcılara sunduğu, işleri kolaylaştıran eklentiler. (Örnek: GCC)
Standart değildir. Farklı bir derleyicide elde edilen sonuçlar değişebilir.

Extended Integer Types
Derleyiciler var olan veri türlerinin dışında eklenti olarak daha geniş sınır aralığı olan tam sayı türleri sağlayabilir.
Örnek: int128_t
-----------------------------------------------------------------------
FLOATING TYPES - IEEE 754 Gerçek Sayı Formatı

4 Byte
(real floating types)
float       (4 Byte)   
double      (8 Byte) (En sık kullanılan gerçek sayı türü)
long double (8/10/12/16 Byte)

(complex types) (C99)
float_Complex      
double_Complex          
long double_Complex      

(imaginary) (C99)
float_Imaginary      
double_Imaginary          
long double_Imaginary  

32 Bitlik Alan => single precision
64 Bitlik Alan => double precision

sign bit
1--------***********************

1 bit: sayının işaretini belirtmek için kullanılıyor
8 bit: sayının büyüklüğü belirtmek için çarpan değerini tutuyor
23 bit: mantissa alanını belirtmek için kullanılıyor

-----------------------------------------------------------------------

DECLARATION (Bildirim)
Bir ismin ne olduğunu anlatan, ifade eden C cümleleridir.
    int x = 10; (Bu C cümlesi bir bildirimdir.)

STATEMENT   (Deyim)
İş yaptırmaya yönelik C cümleleridir.
    x++;

Name Lookup (İsim Arama) (dilin isim arama kuralları)

Derleyici isim arama sürecinde bir ismi arayıp, bulamazsa sentaks hatasıdır.
(name lookup error) örnek hata mesajı: undeclared identifier 


C ve C++ dillerinde isim arama 

a) belirli bir sıraya göre yapılır. (dilin kurallarına göre)
b) isim arama arana ismin bulunmasıyla sona erer, bir daha başlamaz, isim bulunduktan sonra diğer kontroller yapılır.

C dilinde değişken bildirim sentaksı. İki farklı şekilde yapılabilir.

DeğişkenTürü Değişkenİsmi;

int x;
double dval;

DeğişkenTürü Değişkenİsmi = İlkDeğer; (Initialize Etmek, Initialization (ilk değer vermek))

_Bool

char
signed char
unsigned char

short
short int
signed short
signed short int

unsigned short
unsigned short int

int
signed int
signed (varsayılan olarak int türü anlamına geliyor)

unsigned
unsigned int

long
long int
signed long
signed long int

unsigned long
unsigned long int

long long
long long it
signed long long
signed long long it

unsigned long long
unsigned long long int

Değişken ismi iyi seçilmiş olacak.
Türkçe isimlendirme yapmayın.
İyi isim zaman ister.

Konvensiyon (Convention) (Uzlaşım)

camel case
snake case

double valueAddedTaxIncreaseRate; (camel case) (windows sistem programlamada yaygın)
double value_added_tax_increase_rate; (snake case) (unix sistem programlamada yaygın)

Asla değişkenlere ve fonksiyonlara tamamı büyük harf isimlerdirme yapmayın.
Birbirine çok yakın isimler seçmeyin.
-----------------------------------------------------------------------

Scope (Kapsam - Bilinirlik Alanı)
Storage Duration (Ömür)

Nesnelerin ömürleri var. (storage duration) (life span - life cycle)

Programın çalışma zamanında, bir değişken veya bir nesnenin bellekteki bytelardan oluşan kod blokları.
Bu değişkenler bellekte ne kadar süreyle kalacak? Buna storage duration deniyor.

automatic storage class
Programın akışı bir koda girdiğinde nesne hayata geliyor, bellek bir yer ediniyor.
Programın akışı o kod bloğundan çıktığında ilgili bellek alanından çıkıyor.

static storage class
Programın çalışma zamanında bellekteki yerlerini alırlar ve programın sonuna kadar bellekteki yerlerini korurlar.
Programın ömrüyle aynıdır.

dynamic storage class
Programcı bir değişkeni ne zaman hayata başlatmak isterse başlatabiliyor.
Ne zaman sonlandırmak isterse sonlandırabiliyor.

++ Eğer değişken statik ömürlü ise o değişkeni ilk değer vermeden tanımlarsak hayata 0 değeri ile başlar.
++ Eğer değişken otomatik ömürlü ise o değişkeni ilk değer vermeden tanımlarsak hayata garbage value / çöp değeri ile başlar.
(Indetermined Value) (daha önceki programın oluşturduğu byte'larla hayata başlayacak, garbage value)

++İlk değer verilmemiş otomatik ömürlü değişkenleri çöp değeri ile kullanmak tanımsız davranıştır.

Global isim alanında bir değişken bildirimi yapılırsa, global variable olur.
Ve bu değişkenler, statik ömürlü değişkenlerdir. Değiştirilemez.

Lokal isim alanında bir değişken bildirimi yapılırsa, local variable olur.
Ve bu değişkenler, otomatik ömürlü değişkenlerdir.


 */
