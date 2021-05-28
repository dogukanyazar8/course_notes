/*

Ders22

Koda bakarak algoritmanın zaman karmaşıklığını çıkartabilir miyiz?

Aslında evet, dikkatli bakarsak, bazı temel kavramları da biliyorsak evet.

Eğer yapısındaki öğe sayısından bağımsız, tek bir kod yürütülüyorsa o zaman O(1)

Eğer bir döngü varsa, ve döngü veri yapısındaki öğe sayısı kadar ya da bunun bir çarpanı kadar dönüyorsa O(n)

İç içe iki tane döngü varsa, her ikisi de veri yapısındaki öğe sayısı çarpanı kadar dönüyorsa O(n^2)

Bazı durumlarda bunu saptamak çok kolay, bazı durumlarda bunu saptamak zor.

---------------------

Algortima birden fazla basamaktan oluşuyorsa, algoritmanın karmaşıklığı bu basamaklardan karmaşıklığı en yüksek olanın karmaşıklığa eşittir.

Örneğin bir döngü var, döngü veri yapısındaki öğe sayısı kadar dönüyor. Şuanda algoritmanın karmaşıklığı O(n)

for

Sonra sabit bir kod var, döngü dışında, bu O(1), o zaman hâlen O(n)

for

////

Altında da iç içe, veri yapısındaki öğe sayısı kadar dönen iki tane for döngüsü var. O zaman O(n^2)'ye yükseldi. Karmaşıklığı en yüksek olan basamağın karmaşıklığı neyse, algoritmanın karmaşıklığı da o.

for
	for

Algoritmanın karmaşıklığı, veri yapısındaki öğe sayısının az olması durumunda çok da dikkat çekici, önemli değil.
Ama veri yapısındaki öğe sayısının artması durumunda, artık algoritmanın karmaşıklığı çok daha önemli hâle geliyor.

---------------------

O(n) karmaşıklığında bir algoritmaya en güzel örnek, bir veri yapısının ters düz edilmesi. Bu algoritmaya reverse deniliyor.

33 70 97 51 49 47 30 93 49 43 32 89 21 29

Döngünün her turunda baştan n. öğe ile sondan n. öğeyi takas edersek ve bu işi veri yapısındaki öğe sayısının yarısı kadar yapmamız lazım. Yarısı kadar dönen bir döngü gerekiyor.

---------------------
O(n)

Diyelim ki bizim bir veri yapımız var, dizimiz var ve bu dizide bir değer arıyoruz ama dizi sıralı değil. Burada kullanılan algoritmaya linear search deniliyor.
Linear search aslında tek tek bakmak demek. Bu durumda aradığım değerin dizide olmadığını anlamak için dizinin bütün elemanlarına bakmamız gerekiyor.

Peki bu dizi sıralı olsaydı, yani küçükten büyüğe sıralanmış olsaydı ve biz yine bir değer arıyor olsaydık. Neden tek tek bakalım ki?

Dizinin tam ortasına bakardık, aradığım değer değilse,
Dizinin ortasındaki değer aradığım değerden büyükse, büyük olan öğeler devre dışı kalırdı.
Dizinin ortasındaki değer aradığım değerden küçükse, küçük olan öğeler devre dışı kalırdı.

Böylece bulamadığım her bir sorgulama için dizinin yarısını elimine etmiş olurduk.

1000 tane öğe varsa, ilk sorgulamada 500ü, ikinci sorgulamada 250'si, üçüncü sorgulamada 125'i gidecek, bu böyle devam edecek.

Her turda veri yapısındaki eleman sayısının yarısı devre dışı kaldığı için logaritmik karmaşıklık olacak.

---------------------

Algoritmanın karmaşıklığında aşağıdaki gibi kavramlar var.

worst-case scenario
best-case scenario
average scenario

Bazı algoritmalarda, özellikle sıralama algoritmalarında, algoritmanın karmaşıklığı, veri yapısındaki verilerin o algoritma çalıştırılmadan önceki hâliyle ilişkili olabilir.

Bundan dolayı bir çok dökümantasyonda mesela şöyle yazacak, 

worst-case scenario O(n^2)
best-case scenario O(n)
average scenario O(n)

Aksi söylenmedikçe, kastedilen average senaryodur.

---------------------

Space Complexity

İlgili algoritmayı koşturmak için ne kadar ilave bellek alanına ihtiyaç var?

Mesela öyle bir algoritma olabilir ki, sıralamayı başka bir bellek alanı kullanmadan yapıyordur. O zaman bellek alanı karmaşıklığı O(1)

Ama diyelim ki, bir diziyi sıralamak için bizim bir sıralama algoritmamız var, 100 elemanlı bir dizi için onun bir kopyasını oluşturacağız, bunun için bir bellek alanına ihtiyaç var.
Ama o bellek alanı, bizim veri yapımızın kapladığı bellek alanı kadar. O zaman space complexity O(n) olacak.

Yani 1000 elemanlı bir diziyi o işleme sokmak için, 1000 elemanlı bir diziye daha ihtiyacımız var.
Yani 10000 elemanlı bir diziyi o işleme sokmak için, 10000 elemanlı bir diziye daha ihtiyacımız var.

---------------------

Programlama dillerinden bir kısmı, C#, Java, C++ programlamada en çok ihtiyaç duyulan veri yapılarını standart kütüphaneleriyle hazır olarak veriyor.

C++ dilinde vector, dinamik dizi yapısı, bağlı listeler, deque, hash table, hazır geliyor.

Fakat C dilinde durum böyle değil, C dilinde veri yapıları standart kütüphanenin bir bileşeni değil. 

Mesela biz bir linkedlist kullanacağız, ya biz kendi modülümüzü yazacağız ya da 3. parti bir kütüphaneyi kullanacağız.

---------------------

Array - Dizi

C dilinde array denilen bir veri yapısı, dilin doğrudan hazır aracı olarak sunuluyor. Fakat burada array, dinamik dizi veri yapısı değil.
Programlamada, veri yapıları ve algoritmalar terminolojisinde, C dilindeki gibi dizilere fixed array deniliyor.
Yani dizi, kullanıldığı süre boyunca sabit sayıda elemana sahip. Yani ekleme - silme işlemleri yok. Oysa bir veri yapısında en çok duyulan işlemlerden ikisi bunlar.
C'deki diziler ekleme silme semantiğine sahip değil. Fixed Array. Diziler çok sık kullanılan bir araç.

C dilinde bir dizi, aynı türden N tane öğenin bellekte ardışık olarak tutulduğu, tek bir blokta tutulduğu bir veri yapısıdır.

Aynı türden N tane nesne, bellekte tek bir blokta. Örneğin burada 8 tane nesne varsa, bu dizinin boyutu 8. 

Dizinin elemanları belirli bir türden olmak zorunda. Örneğin hepsi int, hepsi long, hepsi double.

1 - Dizinin bir boyutu var ve bu boyut dizi oluşturulurken bir sabit ifadesiyle belirtilmek zorundadır. 

C99 standartlarıyla dile eklenen variable length array denilen araç bir dizinin boyutunun programın çalışma zamanında da belirlenmesini sağlıyor.
Fakat bu araç C'nin C11 standartlarıyla opsiyonel hâle geldi ve derleyiciler vermek zorunda değil.

Pointer operatörlerini kullanarak, dizinin elemanlarından herhangi birisine erişebiliyoruz. 
Buradaki amaç mantıksal ilişki içerisinde verileri bir arada tutmak. Ve index bilgisiyle constant time'da erişmek.
İster 8 elemanı olsun, ister 100 elemanı olsun. Bunlar bellekte ardışık olduğuna göre, bir döngüye ihtiyaç duymadan, ilk öğenin konumunu, adresini biliyorsak, istediğim herhangi bir öğeye bir döngü kodu olmadan erişebiliyoruz.

Ekleme işlemi yok, silme işlemi yok. Ama hâlen bize index bilgisiyle constant time'da istediğim bir elemana erişme şansım var.

Bu dizinin elemanları dediğimiz varlıklar ayrı ayrı değişkenler, sadece bunlar bir arada tutuluyorlar. Yani bu değişkenlerden her birini bir operatör vasıtasıyla ayrı ayrı kullanabileceğiz.

Diğer taraftan, C'deki diziler bazı programlama dillerindeki dizilerden farklı olarak, bir atama semantiğine sahip değil.

Örneği elimizde 10 elemanlı iki tane dizi var. Bir diziyi, diğer bir diziye atamak diye bir şey yok. Dil seviyesinde böyle bir araç yok.

Eğer böyle bir niyetimiz varsa, bir döngü deyimiyle dizinin elemanlarını karşılıklı birbirine atayacak bir kod çalıştıracağız, ya da bu işi yapacak bir fonksiyon söz konusu olacak.

Dizinin her bir elemanı mutable. Ama diziyi bir bütün olarak kullanmak istediğimiz bir semantik yapı yok. immutable.

---------------------

Nasıl değişkenlerin ismi varsa, dizi de bir değişken, onun da bir ismi var.

Sentaksda ilk olarak yazdığımız dizinin elemanları türü, ardından dizinin ismi.

Dizinin tanımında olması gereken bir başka öğe açanan kapanan köşeli parantez ve bu parantezlerin içine dizinin boyutunu gösteren sabit ifadesini yazıyoruz. Örneği 100

Bu ifade eğer variable length array kullanılmayacaksa, ki bunu yok sayıyoruz şimdilik. Bir sabit ifadesi olmalı.

int ar[100];

Aşağıdaki gibi bir kullanım uygun değildir, sentaks hatasıdır. Değişkene bağlı bir ifade olamaz.

int x = 10;

int ar[x];

Aşağıdaki gibi bir kullanım uygundur, çünkü sabit ifadesi.

int ar[10 * 5 * 3 + 6];

---------------------

Diziye eğer ilk değer verilmiyorsa, köşeli parantezin içi boş da olamaz.

int ar[];			 //gecersiz
int ar[0];			 //gecersiz
int ar[-1];			 //gecersiz
int ar[10 * 5 - 50]; //gecersiz

Dizinin boyutunun makrolarla belirtilmesi çok tipik bir durum. 

Çünkü hem kodun okunmasını kolaştırıyor, hem de bu boyut sabit ifadesi kod içerisinde farklı yerlerde de kullanılığında, bunu değiştirmek kolay oluyor.

int ar[SIZE];

---------------------

int a[10]; //10 elemanlı, int türden bir dizi. 10 tane değişken tanımlamış olduk aslında. Fakat bunlar bellekte bir arada ve böyle bir şey yapıyorsak bunların mantıksal bir ilişki içinde olduğunu da ifade ediyoruz.

double a[10];

char a[10];

---------------------

Diziler de initialize edilebilir. İlk değer verilebilir. 

Diziyi çöp değeri ile kullanmak tanımsız davranış. Derleyicilerin çoğu bunu kontrollerle yakalar.

Bir dizi, yerel bir dizi olabilir. Mesela aşağıdaki a dizisi yerel bir dizi. Çöp değerle hayata başlayacak.

#include <stdio.h>

int main()
{
	int a[10];
}

---------------------

Ama yerel bir dizi de statik ömürlü olabilir. Mesela aşağıdaki ar dizisi, yerel bir dizi fakat statik ömürlü.

#include <stdio.h>

void func(void)
{
	static double ar[10];
}

int main()
{
	int a[10];
}

---------------------

Global de bir dizi olabilir. Mesela aşağıdaki ga global bir dizi, bütün global isimlerde olduğu gibi bu isim high scopeda. 
İlk değer verilmediği zaman global değişkenler statik ömürlü olduğu için 0 değeriyle hayata geçecekler.

#include <stdio.h>

int ga[100];

void func(void)
{
	static double ar[10];
}

int main()
{
	int a[10];
}

Dolayısıyla bir dizi, bir yerel değişken olabilir, bir global değişken olabilir, statik ömürlü olabilir, otomatik ömürlü olabilir.

---------------------

Peki ne olamaz? 

Bir fonksiyonun parametre değişkeni dizi olamaz.
Bir fonksiyonun geri dönüş değeri türü bir dizi olamaz.

Diziler, fonksiyonlardan fonksiyonlara, adres yoluyla geçiliyorlar. Dizilerin call by value olarak fonksiyonlara gönderilmesi C ve C++'da mümkün değil.
Dolayısıyla, bir fonksiyon, bir fonksiyona bir dizi gönderecekse, fonksiyona dizinin adresini göndermek zorundadır.
Fonksiyondan fonksiyona dizi aktarımı için pointer konusunu bilmemiz gerekiyor. 

Ama fonksiyonun geri dönüş değeri bir dizinin adresi olabilir.

Gerek geri dönüş değeri tarafında gerek parametre tarafında, aktarım her zaman adres semantiğiyle oluyor.

---------------------

int a[5]; -> Bu dizinin 5 tane elemanı var, değişkenim var. Ben bu değişkenlerden istediğim herhangi birini kullanabilirim.

Ayrıca;

int x, y, z;	-> Biz dizi değil de, bağımsız, ayrı isimlendirilmiş, 3 tane ayrı değişken tanımlasaydık, bu 3 tane değişkenin bellekte derleyici tarafından yeri ayrıldığında, bellekte birbirinin peşi sıra yerleştirme garantisi yoktur.

int a[3];		-> Ama bu şekilde 3 elemanlı bir dizi oluştursam, bunun artık bellekte tek bir blok olması garanti altında.

Bu elemanlardan her birine nasıl erişiriz? Bunun için pointerlar konusunda göreceğimiz bir operatör kullanıyoruz.

Index Operator - Subscript Operator

Dizinin herhangi bir elemanına erişmek için operatör seviyesinde bir işleme ihtiyacımız var.

dizinin_ismi[tamsayi_ifadesi] parantez içerisindeki ifade 5 ise, dizinin 5. elemanına erişiyoruz.

C ve C++'da dizinin ilk elemanı dizinin 0 indexli elemanı.

int a[10];
a[0]; -> a dizisinin ilk elemanı
a[1]; -> a dizinin birinci indisli elemanı.


a[SIZE];		-> Bu şekilde bir dizimiz olsun.
a[0];			-> Dizimizin ilk elemanı.
a[SIZE - 1];	-< Diziminin son elemanı.

---------------------

int a[10];

Dizi için bellekte ayrılan yer, dizinin eleman sayısı * bir elemanın ihtiyaç duyduğu yer kadar.

Bizim sistemimizde int türü 4 byte, o zaman a dizisi için bellekte 4 * 10 byte'lık, yani 40 byte'lık bir yer ayrılacak.

---------------------

Diyelim ki 10 elemanlı bir dizimiz var, işlem yaparken öyle bir ifade yazdık ki, a[expr] bu ifadenin değeri 10 ya da daha büyük değer.

Bu bir sentaks hatası mıdır? Sentaks hatası değilse tanımsız davranış mıdır?

Kesinlikle sentaks hatası değildir. Örneğin aşağıdaki gibi bir kod yazdığımızda, derleyicinin herhangi bir şekilde ne burada bir sabit ifade yazmamız, ne de burada bir değişken ifadesi yazmamız durumunda derleyicinin bir kontrolüne tabii değil.

Yani diziyi taşırmak veya dizinin olmayan bir elemanına erişmek diyelim, bunlar compile time hatası değil, runtime hatası ve tanımsız davranış.

Dizinin elemanlarına erişirken köşeli parantez operatörünü kullanırken dikkatli olmamız gerekir.

int main()
{
	int a[10];

	a[10] = 5;
}

---------------------

Dizinin elemanlarına erişmenin en sık karşılaşılan biçimi döngüsel bir yapı içerisinde döngünün elemanlarının hepsine erişmek.

Array traversal -> diziyi dolaşmak, dizinin elemanlarını dolaşmak
Linkedlist traversal -> bağlı listeyi dolaşmak, bağlı listenin elemanlarını dolaşmak

#include <stdio.h>

int main()
{
	int a[10];

	for (int i = 0; i < 10; ++i) {
		a[i] = 0;
	}

	for (int i = 0; i < 10; ++i) {
		printf("a[%d] = %d\n", a[i], i);
	}
}

---------------------

Köşeli parantez operatörüyle dizinin bir elemanına eriştiğimizde, bu bir değişken. 

Bir değişkenle hangi işlemleri yapabiliyorsak, dizinin herhangi bir öğesiyle de bu işlemleri yapabiliriz.

[] -> Operatör öncelik seviyesinde en yüksek öncelikli seviyede.

---------------------

Array Initialization - Dizinin elemanlarına ilk değer verme sentaksı

Bir dizi ister global, ister yerel, ister otomatik ömürlü yerel, ister statik ömürlü yerel olsun, diziye bir sentaks kuralı dahilinde ilk değer verebiliriz.

#include <stdio.h>

int main()
{
	int a[10] = { 1, 3, 5, 7, 9, 12, 4, 8, 48, 24, 13};

	for (int i = 0; i < 10; ++i) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

Diziye ilk değer verirken initializer'ların sayısı, dizinin belirten boyutundan daha fazlaysa, doğrudan sentaks hatası.

10 elemanlı bir diziyi, 11 tane ilk değerle hayata başlatamayız. -> too many initializers

Eğer ilk değer verme sentaksındaki, ilk değer veren ifade sayısı, dizinin belirtilen boyutundan daha küçükse, 
bu durumda dizinin otomatik veya statik ömürlü olduğundan bağımsız olarak, ilk değer verilmeyen öğelerin tamamı 0 değeriyle hayata başlayacaktır.

#include <stdio.h>

int main()
{
	int a[10] = { 1, 3, 5, 7, 9 };

	for (int i = 0; i < 10; ++i) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

Ekran Çıktısı:

a[0] = 1
a[1] = 3
a[2] = 5
a[3] = 7
a[4] = 9
a[5] = 0
a[6] = 0
a[7] = 0
a[8] = 0
a[9] = 0

---------------------

Küme parantezinin içine sadece 0 yazmak, 
bu durumda bu dizinin ilk elemanına verilen ilk değer 0, diğerlerine de ilk değer verilmediği için dizinin tamamını 0 değeriyle hayata başlatmak için kullanılan bir idiom.

int a[100] = { 0 };

#include <stdio.h>

#define			SIZE		100

int main()
{
	int a[SIZE] = { 0 };

	for (int i = 0; i < SIZE; ++i) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

Fakat C dilinde küme parantezinin içini boş bırakma hakkımız yok. Sentaks hatasıdır.

---------------------

Diziye ilk değer verirken son initializerdan sonra boşta duran bir virgül atomu olabilir. 
İlk değer verme listesindeki boşta duran virgüle trailing comma deniliyor. Bu bir sentaks hatası değil.

int a[5] = {1, 2, 3, 4, 5,}; -> Bu geçerli.

int a[]; -> Bu geçerli değil.

int a[] = {1, 2, 3, 4, 5};

---------------------

Diziye ilk değer veriyorsak dizinin boyutunu belirtmek zorunda değil. Bu durumda derleyici compile time'da koda bakarak ilk değerlerin sayısını çıkartacak, ve sayı neyse, köşeli parantezin içine o sayıyı yazmışsınız kabul edecek.
Dizinin boyutunu ister belirtirim, ister belirtirim. Ama belirtmemek için, diziye ilk değer vermek şart.

Çalışma zamanında diziye eleman eklemek, silmek diye bir şey yok. 

Eğer amacımız runtime'da ekleme ve silme yapabilsekse, yani runtime'da dizinin boyutunu istediğimiz gibi değiştirmekse, dinamik bellek yönetimi dediğimiz aracı kullanmak zorundayız.

C89
C95
C99 - Major changes

C99 standartlarıyla dile eklenen önemli araçlardan biri designated initializer. Belirlenmiş ilk değerler diyebiliriz.

Dizilere ilk değer vermede kullanılan bir sentaks. Bu birden fazla olabilir.

int a[20] = { [5] = 17, [13] = 25 }; 

Bu şu anlama geliyor, ben dizinin 5 indeksli elemanını 17 ilk değeriyle, 13 indeksli elemanını 25 ilk değeriyle hayata başlatıyorum.

Belirli bir sıra takip edilmez zorunda da değil, yani önce 15., sonra 5. indeks diyebilirdik.

int a[20] = { [15] = 17, [5] = 25 }; 

Geriye kalan öğeler, 0 değeriyle hayata başlayacak.

#include <stdio.h>

int main()
{
	int a[20] = { [5] = 17, [13] = 25 };

	for (int i = 0; i < 20; ++i) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

---------------------

int a[20] = { [5] = 17, [13] = 25, 75 };

Peki diziye yukarıdaki gibi ilk değer verirsek ne olur, sentaks hatası mıdır? 

Hayır, bu yapı pek kullanılmaz. Bir sonraki indeksli elemanı 75 ilk değeri ile başlatılıyor.

---------------------

Ayrıca dizinin boyutunu belirtmeden de designated initializer kullanabiliriz.

Bu durumda dizinin boyutu kullanılan en büyük indeks + 1 olacak.

int a[] = { [5] = 17, [13] = 25, 75 };
//size of a is 14

Bu sentaksın geçerli olabilmesi için köşeli parantezin içindeki ifadenin yine bir sabit ifadesi olması gerekiyor.

Aşağıdaki gibi bir ifade yazamayız. Doğrudan sentaks hatasıdır.

	int a[] = { [x] = 10, [10] = 15 }; //error C2057: expected constant expression

Standart olarak dizinin elemanlarına verilen ilk değer ifadeleri de bir sabit ifadesi olmak zorunda.

	int x = 5;
	int y = 10;
	int z = 10;

	int a[] = { x, y, z, x + y};

Ama derleyicilerin hemen hepsi, eklentiyle bunu mümkün kılıyor. Yani %100 taşınabilirlik aramıyorsak, bunu kullanabiliriz. Ama bu bir eklenti.

---------------------

Dizi tanımlamalarında virgüllerle ayrılan liste kullanılabilir. Pek tercih edilen bir yapı değil.

	int a[5], b[10];

Veya şöyle de olabilir:

	int x, y, z, a[5], b[10];

---------------------

Şöyle bir işlem yapmak istiyoruz, aşağıdaki kodda b'nin her elemanına, a'nın karşılıklı elemanı atansın.
Hayır, bu her zaman sentaks hatasıdır.

#include <stdio.h>

int main()
{
	int a[5] = { 1, 3, 5, 7, 9 };
	int b[5];

	b = a; //sentaks hatası
}

Diziler atama operatörlerinin sol operandı olamazlar. Bu durum atama operatörünün sağ operandının ne olduğuyla ilgili de değildir.

Problem dizi isminin, atama operatörünün sol operandı olamayışı. Bu konu pointer konusuyla daha da iyi anlaşılacak fakat kısaca aşağıdaki gibi açıklanabilir.

#include <stdio.h>

int main()
{
	int x = 10;

	&x = 
	
}

C dilinde adres operatörü ile oluşturulan bir ifade sol taraf değeri, l value expression değildir, sağ taraf değeridir.

Adres operatörüyle oluşturulan bir ifade, atama operatörünün sol operandı olamaz.

C'deki Array Decay kuralı. Bir başka terim, Array to pointer conversion.

Bir dizinin ismini bir ifade içinde kullandığımızda, derleyici dizi ismini kullanmış olmanıza rağmen, bu ifadeyi derleme zamanında sanki biz dizinin ilk operandının adres operatörüyle adresini almışız gibi ele alıyor.

a -->>>> a[0] //bunu yazmışız gibi ele alıyor.

Yani dizi ismi derleyici tarafından, bir ifade içinde kullanıldığında otomatik olarak dizinin ilk elemanının adresine dönüştürülüyor.

Bir ifade içinde dizi isminin kullanılması durumunda, derleyicinin dizi ismini, dizinin ilk elemanının adresine dönüştürmesine array decay, array to pointer conversion deniliyor.

Dolayısıyla bir kodda dizinin ilk elemanının adresini, adres operatörüyle almamızla, doğrudan bunun yerine dizi ismini yazmamız arasında bir fark yok.

a = &a[0]

Bunu kanıtlamak ve daha iyi anlamak için aşağıdaki örneğe bakılabilir.

#include <stdio.h>

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };

	printf("a[0] = %d\n", a[0]);
	printf("Bir sayi giriniz: ");
	scanf("%d", &a[0]);
	printf("a[0] = %d\n", a[0]);
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };

	printf("a[0] = %d\n", a[0]);
	printf("Bir sayi giriniz: ");
	scanf("%d", a);
	printf("a[0] = %d\n", a[0]);
}

Dizinin ismi olan a ile a[0] aynı anlamda. Dizinin ilk elemanın adresini yazmakla, dizinin ismini yazmamız arasında bir fark yok.

Neden dizi ismi atama operatörünün sol operandı olamıyor, çünkü biz a = dediğimizde, derleyici bu ifadeyi &a[0] biçiminde ele alıyor.

Adres operatörüyle oluşturulan bir ifade sol taraf değeri olmadığı için sentaks hatası oluyor.

Eğer amacımız, bir diziye, bir diziyi atamaksa, bunu yapmanın en kolay yolu standart bir C fonksiyonuna çağrı yapmak. //memcpy bellek kopyalama fonksiyonu

Standart bir C fonksiyonuyla yapmak istemiyorsak bir döngüde bunu yapabiliriz.

#include <stdio.h>

int main()
{
	int a[5] = { 10, 20, 30, 40, 50 };
	int b[5];

	for (int i = 0; i < 5; ++i) {
		b[i] = a[i];
		printf("b[%d] = %d\n", i, b[i]);
	}
}

---------------------

dutility.h başlık dosyasında aşağıdaki fonksiyonların bildirimlerini yapıp, ilgili fonksiyonları dutility.c kaynak dosyasında tanımladık.

void randomize(void);
void print_array(const int* p, int size);
void set_random_array(int* p, int size);

Bazı kodları tekrar tekrar yazmamak için yukarıdaki gibi fonksiyonlar tanımladık, böylece test kodu oluşturmamız çok daha hızlı ve pratik olacak.

---------------------

Soru1: Bir tam sayı dizisinin bütün elemanlarının toplamını bulunuz.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int sum = 0;

	for (int i = 0; i < SIZE; ++i) {
		sum += a[i];
	}

	printf("sum = %d", sum);
}

---------------------

Soru2: Yukarıda yazdığımız, dizinin elemanlarının toplamını bulma algoritmasının Big O notasyonunda karmaşıklığı nedir?

Cevap: O(n). Çünkü dizinin boyutuyla ilişkili bir döngü var.

---------------------

Soru3: Aşağıdaki programda "exp" yazan yere bir ifade yazacağız ve bu ifade dizinin aritmetik ortalaması anlamına gelecek.

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int sum = 0;

	for (int i = 0; i < SIZE; ++i) {
		sum += a[i];
	}

	printf("ortalama = %f\n", exp);
}

Cevap:	printf("ortalama = %f\n", (double)sum / SIZE);

---------------------

Soru4: Aşağıdaki dizinin yalnızca tek (odd) olan elemanlarının aritmetik ortalamasını hesaplayın.

Cevap: Cevap olarak yazdığımız aşağıdaki kodda bir hata var. 0'a bölme hatası. Eğer dizinin tek sayı yoksa, 0'a bölme hatası olur. Undefined Behavior. Tanımsız davranış.

Hiç kimse ben 0'a bölme hatası yaparım demez ama 0'a bölme hataları böyle oluşuyor. Belirli senaryoları dikkate almamaktan dolayı.

Dolayısıyla odd_count'un değeri 0'sa, tanımsız davranış olacak.

Ayrıca işaretli türlerde taşma, tanımsız davranıştır.

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int odd_sum = 0, odd_count = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] % 2 != 0) {
			odd_sum += a[i];
			++odd_count;
		}
	}

	printf("teklerin ortalamasi = %f\n", (double)odd_sum / odd_count);
}

---------------------

(Taşmaya dikkat edilmesi gerekin)Tanımsız davranış olmayan, doğru cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int odd_sum = 0, odd_count = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] % 2 != 0) {
			odd_sum += a[i];
			++odd_count;
		}
	}

	if (odd_count)
		printf("Teklerin ortalamasi = %f\n", (double)odd_sum / odd_count);
	else
		printf("Dizide hic tek sayi yok\n");
}

---------------------

Soru5: Aşağıdaki dizide hem çift hem de teklerin aritmetik ortalamasını ayrı ayrı hesaplayın.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int odd_sum = 0, odd_count = 0;
	int even_sum = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] % 2 != 0) {
			odd_sum += a[i];
			++odd_count;
		}

		else {
			even_sum += a[i];
		}
	}

	if (odd_count)
		printf("Teklerin ortalamasi = %f\n", (double)odd_sum / odd_count);
	if (SIZE - odd_count)
		printf("Ciftlerin ortalamasi = %f\n", (double)even_sum / (SIZE - odd_count));
}

---------------------

Soru6: Yukarıdaki algoritmanın Big O notasyonunda karmaşıklığı nedir? Hem teklerin hem çiftlerin aritmetik ortalamasını hesaplama.

Cevap: O(n)

---------------------

Soru7: Max element algoritması. Bir dizinin en büyük elemanının bulunması.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int max = a[0];

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] > max)
			max = a[i];
	}

	printf("Dizinin en buyuk elemani = %d", max);
}

---------------------

Soru8: Yukarıdaki algoritmanın Big O notasyonunda karmaşıklığı nedir?

Cevap: O(n)

---------------------

Soru9: Aşağıdaki dizide sadece en büyük elemanı değil, en büyük elemanın indeksini de bulmak istiyoruz.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int max = a[0], max_idx = 0;

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] > max) {
			max = a[i];
			max_idx = i;
		}
	}

	printf("Dizinin en buyuk elemani = a[%d] = %d", max_idx, max);
}

---------------------

Soru10: Aşağıdaki dizinin hem en büyük elemanını hem de en küçük elemanını bulunuz.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int max = a[0], min = a[0];

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] > max) {
			max = a[i];
		}

		else if (a[i] < min) {
			min = a[i];
		}
	}

	printf("Max = %d\n", max);
	printf("Min = %d\n", min);
}

---------------------

Soru11: Müsabakalarda 2. olan kişiye runner up deniliyor. Soru, dizinin en büyük elemanını değil, runner up'ın bulunuz. En büyük 2. elemanı

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int runner_up = a[0];
	int max = a[1];

	if (a[0] > a[1]) {
		max = a[0];
		runner_up = a[1];
	}

	for (int i = 2; i < SIZE; ++i) {
		if (a[i] > max) {
			runner_up = max;
			max = a[i];
		}

		else if (a[i] > runner_up) {
			runner_up = a[i];
		}
	}

	printf("Max = %d\n", max);
	printf("Runner-up = %d\n", runner_up);
}

---------------------

Soru12: Dizinin unique, eşsiz elemanlarını bulunuz

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	20

int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i)
		a[i] = rand() % 20;
	print_array(a, SIZE);

	int count;

	for (int i = 0; i < SIZE; ++i) {
		count = 0;
		for (int j = 0; j < SIZE; ++j) {
			if (a[i] == a[j])
				++count;
		}

		if (count == 1)
			printf("%d\t", a[i]);
	}
}

---------------------

Soru13: Reverse, diziyi tersine çevirme, ters yüz etme.

Cevap:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	100

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	for (int i = 0; i < SIZE / 2; ++i) {
		int temp = a[i];
		a[i] = a[SIZE - 1 - i];
		a[SIZE - 1 - i] = temp;
	}

	print_array(a, SIZE);
}

O(n) karmaşıklığında. 

---------------------

Soru14: Reverse copy - Dizinin elemanlarını, başka bir diziye ters çevirip kopyala.

Cevap: 

#include <stdio.h>
#include "dutility.h"

#define		SIZE	10

int main()
{
	int a[SIZE];
	int b[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		int temp = a[i];
		b[i] = a[SIZE - 1 - i];
		b[SIZE - 1 - i] = temp;
	}

	print_array(b, SIZE);
}

---------------------

Soru15: Linear Search Algoritması - Dizinin bir elemanının ilk geçtiği yeri bulunuz.

Cevap1:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int i, sval, flag = 0;

	printf("Aranan degeri giriniz: ");
	(void)scanf("%d", &sval);

	for (i = 0; i < SIZE; ++i) {
		if (a[i] == sval) {
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("Bulundu! Dizinin %d indisli elemani!", i);
	else
		printf("Bulunamadi!");
}

Cevap2:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int i, sval;

	printf("Aranan degeri giriniz: ");
	(void)scanf("%d", &sval);

	for (i = 0; i < SIZE; ++i) {
		if (a[i] == sval) {
			break;
		}
	}

	if (i < SIZE)
		printf("Bulundu! Dizinin %d indisli elemani!", i);
	else
		printf("Bulunamadi!");
}

Cevap3:

#include <stdio.h>
#include "dutility.h"

#define		SIZE	10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	int i, sval;

	printf("Aranan degeri giriniz: ");
	(void)scanf("%d", &sval);

	//Lojik ve operatörünün kısa devre davranışı, i < SIZE yanlışsa, 2. kısım yapılmaz.
	//Eğer i < SIZE'a eşit olursa, diğer kısma bakılmayacak.
	//Ama 2. kısım yanlış olduğu için döngüden çıkılırsa, demek ki i < SIZE halen doğru olacak.

	for (i = 0; i < SIZE && a[i] != sval; ++i) {
		;
	}

	if (i < SIZE)
		printf("Bulundu! Dizinin %d indisli elemani!", i);
	else
		printf("Bulunamadi!");
}

---------------------

ÖDEV

Soru16: Her bir karşılaştırma işlemi 1 işlem. Arttırma da 1 işlem. Aranan değer veri yapısında olmadığı zaman, 3 * SIZE kadar işlem yapmış oluruz.

Kodu yeniden düzenleyerek 2 * SIZE kadar işlem yapılmasını sağlayabilir misiniz?

---------------------

Sıralama Algoritmaları - Sorting Algorithms

Sıralama bir veri yapısındaki öğelerin belirli bir ilişki biçimine göre yeniden konumlandırılması demek.

Büyükten küçüğe - Küçükten büyüğe veya bambaşka bir ilişki olabilir.

Sıralama algoritmasıyla sıralama kriteri ayrı kavramlar.

Sıralama algoritması, işin nasıl yapılacağını tarif ediyor. Burada anahtar nokta dizinin iki elemanı belirli yerlerde takas edilecek.
Sıralama kriteri ise, hangi koşul sağlandığında takas yapılacağı anlamına geliyor.

Dolayısıyla aynı sıralama algoritmasını kullanarak farklı sıralama kriterlerini kullanabiliriz.

Çok fazla sıralama algoritması var. Hepsinin spesifik avantajları, dezavantajları olabilir. Bunlar belirli kriterlere göre kategorize edilebilir.

Sıralama algoritmalarının karmaşıklığı özel bir koşul söz konusu değilse,

O(nlogn)
O(n2)

Bir sıralama algoritmasının bizi ilgilendiren özellikleri:

Time Complexity
Space Complexity

Sıralam algoritması stable olabilir, unstable olabilir.

Her bir sıralama algoritması için onun stable ya da unstable olması, bizi bir çok durumdan etkiliyor. Kararlı veya Kararsız.

Diyelim ki, bizim sıralamaya konu verilerimiz kişiler ve kişileri isimlerine göre sıralayacağız.
Biz bunları bir sıralama kriteriyle sıraladığımızda, aynı değerde olan anahtarlar bir araya gelecek.
Bir sıralamayı isme göre yapıyoruz ama bunlar farklı farklı varlıklar. Hangi "metin" daha önde? Biz isme göre sıraladığımızda metin anahtarı aynı olduğu için bunlar bir araya gelecek.


metin	56
ahmet
leyla
metin	42
sinan
begum
metin	49

ahmet	56
begum	42
leyla
metin	42
metin	49
metin	56
sinan

Aynı anahtar olanlar, aynı değerde olanlar, sıralamadan önceki konumlarıyla, sıralamadan sonraki izafi konumları değişti.
Eğer algoritma, bize aynı anahtar değerlerinin sıralamadan önceki izafi konumunu koruma garantisi veriyorsa, o algoritma stable sort algoritmasıdır. 

Stable olması için sıralamadan sonra da bu "metin" değerlerinin, sıralamadan önceki konumlarını koruması gerekiyordu.

Stable sort'un önemi.

Bu sefer bu verileri yaşa göre sıraladığımızı düşünelim. Eğer ikinci sıralama stable sort algoritmasıyla, sıralama kriterini değiştirdiğimizde ilk sıralama kriteri bozulmayacak.
Bunları yaşa göre sıraladığımızda, ahmet - metin aynı yaştaysa, 56 yaşında olanların arasında ahmet daha başta, metin daha sonra olacak.
Böylece ilk sıralamanın etkisi bozulmayacak.

---------------------

Sıralama algoritmasının time complexity'si önemli. Burada duruma göre best case, worst case, average case.
Sıralama algoritmasının space complexity'si önemli. İlave bir bellek alanına ihtiyaç duyuluyor mu, duyulmuyor mu.
Sıralama algoritması stable olabilir, unstable olabilir.

---------------------

*/
