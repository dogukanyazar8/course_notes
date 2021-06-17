/*

Ders23

Sıralama kriteri öğelerin sıralama işleminden sonra nasıl bir düzenle konumlandırılacağını açıklıyor. Küçükten büyüğe gibi.

Sıralama algoritması ise hangi basamakta neler yapılacak nerede döngü olacak nerede swap yapılacak onları anlatıyor.

Sıralama algoritmalarının tipik olarak karmaşıklık seviyesi O(nlogn) veya O(n^2) olabiliyor.

Time Complexity
Space Complexity

Bubble Sort Algoritması - Kabarcık Sıralaması Algoritması

Bu algoritmada su kabarcıkların dipten yüzeye yükselmesi gibi döngüsel bir yapı içerisinde dizinin elemanları sıralama kriteri neyse yerini alıyor.

188 252 231 748 529 485 841 674 752 940

Ardışık iki tane elemanı doğru yerde mi sorgulamasına sokuyoruz, bu elemanlar sıralama ilişkisine göre doğru yerdeyse, bunlara dokunmuyoruz ama yanlış yerdeyse bunları takas ediyoruz.

Örneğin küçükten büyüğe sıralama yapılacaksa;

[188 252] [231 748] [529 485] [841 674] [752 940]

188 252 231 748 485 529 674 841 752 940

Dizinin n tane öğesi varsa, dizinin n tane öğesini konumlandırmak için n - 1 tane karşılaştırma yapmak gerekir.

O zaman n - 1 tane öğeyi konumlandırmak için n - 1 * n - 1 kez dönen döngüye ihtiyacımız var. O(n) karmaşıklığı.

Örnek bubble sort implementasyonu - küçükten büğüye sıralama - O(n^2) karmaşıklığı

//Dıştaki döngü SIZE - 1 kez dönüyor çünkü SIZE - 1 öğeyi yerine koyarsak, geriye kalan öğe de mecbur yerine gelmiş olacak

//Dıştaki döngünün her turundan sonra içteki döngü 1 eksik dönebilir, o yüzden döngünün koşul ifadesini SIZE - 1 - i biçiminde yapıyoruz.

#include <stdio.h>
#include "dutility.h"

#define SIZE 10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	//kucukten buyuge siralama
	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if (a[k] > a[k + 1]) {
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}

	print_array(a, SIZE);
}

---------------------------------------

Eğer sıralama kriteri if parantezi içine yazdığımız ifadeyle temsil ediliyorsa, 
buraya öyle bir ifade yazınız ki, bu dizi sıralandığında tekler başta, çiftler sonda olsun 
Ve tekler kendi içinde küçükten büyüğe sıralı, ve çiftler kendi içinde küçükten büyüğe sıralı olsun.

Algoritma değişmeyecek sadece if parantezi içindeki ifade değişecek.

Hangi koşulda swap yapmalıyız.

a[k] çift ise a[k + 1] tek ise 
a[k] ve a[k + 1] bunların oddity'si aynıysa ve a[k], a[k + 1]'den büyükse.

Örneğin 23 13. İkisi de tek. Küçük olan tek, büyük olan tekden daha önce gelmeli. Swap yapmalıyım.
Örneğin 38 26. İkisi de çift. Küçük olan çift, büyük olan çiftden daha önce gelmeli. Swap yapmalıyım.

#include <stdio.h>
#include "dutility.h"

#define SIZE 10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	//kucukten buyuge siralama
	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if ((a[k] % 2 == 0 && a[k + 1] % 2 != 0) || (a[k] % 2 == a[k + 1] % 2) && (a[k] > a[k + 1])) {
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}
	print_array(a, SIZE);
}

---------------------------------------

Bubblesort algoritmasının karmaşıklığı O(n^2). Quicksort algoritmasının karmaşıklığı O(nlogn).

Şimdi bir diziyi, hem bubblesort algoritmasıyla hem de quicksort algoritmasıyla sıralayacağız ve sürelerini ölçeceğiz.

Dizinin boyutunu 100000 ayarlıyoruz fakat burada stack'de yani otomatik ömürlü nesneler için ayrılan bellek alanında, 100bin 200bin 1milyon elemanlı dizi oluşturma şansımız yok.
Bundan dolayı diziyi dinamik olarak oluşturuyoruz. Yani yerini runtime'da elde ediyoruz. Bu durumda dizimiz Heap dediğimiz bellek alanında oluşturulacak.

İlk olarak SIZE elemanlı bir diziye, malloc fonksiyonuyla programın çalışma zamanında bir yer ayırıyoruz.

Bubblesort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 10.142000 saniye

1 milyon öğesi olsaydı, 100binden 1milyona çıkması 10 kat artması demek, birebir O(n2) olsa c sabiti 1 olsa, 10 kat arttığına göre 1milyon elemanda 100 kat artacak.

100 * 10(100.000 eleman süresi) = 1000 Saniye 

5 milyon öğe olsaydı, bu 50 katına çıkacaktı. 50'nin karesi 2500. 2500 * 10 = 25000 Saniye

Bubblesort Kodu:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dutility.h"

#define SIZE 100'000

int main()
{
	int* p = (int*)malloc(SIZE * sizeof(int));
	if (!p) {
		fprintf(stderr, "Bellek yetersiz!\n");
		return 1;
	}

	set_random_array(p, SIZE);

	printf("Siralama basladi!\n");

	clock_t start = clock();

	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if (p[k] > p[k + 1]) {
				int temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	}

	clock_t end = clock();

	printf("Siralama bitti! %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
}

---------------------------------------

Quicksort Kodu:

Standart kütüphanenin zaten bu işi yapan stdlib.h başlık dosyasında bildirilen qsort isimli fonksiyon var.

Bubblesort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 10.142000 saniye

Quicksort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 0.006000 saniye

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dutility.h"

#define SIZE 5'000'000

int icmp(const void* vp1, const void* vp2)
{
	return *(const int*)vp1 - *(const int*)vp2;
}

int main()
{
	int* p = (int*)malloc(SIZE * sizeof(int));
	if (!p) {
		fprintf(stderr, "Bellek yetersiz!\n");
		return 1;
	}

	set_random_array(p, SIZE);

	printf("Siralama basladi!\n");

	clock_t start = clock();

	qsort(p, SIZE, sizeof(*p), icmp);

	clock_t end = clock();

	printf("Siralama bitti! %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
}

---------------------------------------

icmp fonksiyonu nedir? Bu tür fonksiyonlara callback functions deniliyor. 
qsort fonksiyonu dizinin elemanlarının türlerini bilmediği için, karşılaştırmanın nasıl yapılacağı bilgisini kendisini çağıran koddan alıyor.
bir fonksiyonu, bir fonksiyona argüman olarak gönderiyoruz.

qsort, bizim dizimizin elemanlarını karşılaştırmak için bizim sana adresini gönderdiğimiz fonksiyonu çağıracaksın.

Bir fonksiyona bir fonksiyonu argüman olarak gönderme yapısına callback deniliyor.

---------------------------------------

Dizinin unique olan elemanlarının bulunması:

Birincisi O(n^2) karmaşıklığı olduğu kesin. İç içe iki tane döngü olacak.

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 20

int main()
{
	int a[SIZE];

	randomize();

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 20; //0 - 20 aralığında değer atıyoruz rastgele.
	}

	print_array(a, SIZE);

	int i, k;

	for (i = 0; i < SIZE; ++i) {
		for (k = 0; k < SIZE; ++k) {
			if (i != k && a[i] == a[k]) // a[i] -> unique değil. eğer içteki döngüden break deyimi ile çıkmışsak, a[i] unique değil. ama break ile değil de, k'nın SIZE'dan küçük olmasından dolayı çıkmışsak, o zaman kesinlikle a[i] unique.
				break;
		}

		if (k == SIZE)
			printf("%3d ", a[i]);
	}
}

---------------------------------------

O(n) karmaşıklığında unique elemanları bulma.

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 20

int main()
{
	int a[SIZE];
	int cnt[20] = { 0 }; // cnt dizisi 0 - 19 arasındaki değerlerden her birinden kaç tane var, bu değeri tutacak.
						// örnek olarak, cnt dizisinin 0 indisli elemanı, a dizisinde kaç tane 0 var, bu değeri tutacak gibi.
	randomize();

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 20;
	}

	print_array(a, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		++cnt[a[i]]; // cnt dizisinin, a[i] elemanının değerini, 1 arttırıyoruz.
	}

	//Bu döngüden sonra, cnt dizisine bakarsak, örneğin cnt dizisinin 5 indisli elemanı eğer 1 ise, dizide 1 tane 5 elemanı var demek.
	//Bu döngüden sonra, cnt dizisine bakarsak, örneğin cnt dizisinin 5 indisli elemanı eğer 3 ise, dizide 3 tane 5 elemanı var demek.

	//Şimdi cnt dizisinin elemanlarını dolaşıyoruz.

	for (int i = 0; i < 20; ++i) {
		if (cnt[i] == 1)
			printf("%3d ", i);
	}

	//Böylece yardımcı bir dizi kullanarak, değerlerinde sadece belirli aralıkta olmasından faydalanarak unique olanları küçükten büyüğe yazdırdık.
}

---------------------------------------

Subsequence problemi için örnek dizi oluşturma kodu:


	
	srand(14012021);
	for (int i = 0; i < 100; ++i){
		if(i && i % 10 == 0)
			printf("\n");
		int x = (rand() % 2 ? 1 : -1) * (rand() % 1000);
		printf("%d, ", x);
	}

	printf("\n");

Örnek Dizi:

	int a[SIZE] = {
		159, 723, 88, 415, -41, 351, -713, 953, -362, -374, 
		786, 600, 979, -102, -645, 613, 777, -546, -657, 765, 
		-231, 568, 836, -777, 698, 523, 100, 308, 332, -138, 
		-853, 119, -714, 575, -814, -416, -582, 274, 340, -966, 
		189, 435, -821, -711, -225, 291, -198, -698, 136, -316, 
		174, 262, 236, -76, 832, -769, -609, -550, -669, -298, 
		-491, 25, -168, -879, 197, 143, 792, 455, 786, 294, 
		754, 458, -952, -715, 964, 420, -480, 211, -619, 678, 
		-728, 912, -486, 708, -809, -586, -609, 328, -961, 187, 
		787, -382, 994, 593, 240, -134, 313, 512, -671, 221,
	};

---------------------------------------

ÖDEV:

Bir tane dizimiz var. Bu dizinin en az bir elemanı negatif değerde. Birden fazla negatif değer de olabilir.

int a[] = {12, -5, 34, -45, 5, 90, 23, 45};

sub-sequence
sıralı alt dizi / ardışık alt dizi

Bir dizinin ardışık n tane elemanının oluşturduğu alt diziler birer sub-sequence.

Dizinin tamamı bir sub-sequence. Dizinin bir elemanı sub-sequence.

Ama aşağıdaki bir sub-sequence değil.

{12, -5, 90}

Sub-sequence olması için bütün öğelerin ardışık olması gerekiyor.

Her sub-sequence'ın bir toplamı var.

{12, -5, 34} -> 41

{-45, 5, 90, 23, 45} -> 118

{-45, 5, 90,} -> 50

Problemin ismi maximum sub-sequence problem. Bir dizinin olabilecek en büyük alt dizi toplamının değeri isteniyor.

Diğer bir soru, bu problemi çözen algoritmanın karmaşıklığı nedir? Big O notasyonunda nasıl ifade edilir.

Bunun ideali O(n) karmaşıklığıdır. 

SORU: Aşağıdaki dizinin max. sebsequence değerini O(n) karmaşıklığında bir algoritma ile hesaplayınız.

	int a[SIZE] = {
		159, 723, 88, 415, -41, 351, -713, 953, -362, -374, 
		786, 600, 979, -102, -645, 613, 777, -546, -657, 765, 
		-231, 568, 836, -777, 698, 523, 100, 308, 332, -138, 
		-853, 119, -714, 575, -814, -416, -582, 274, 340, -966, 
		189, 435, -821, -711, -225, 291, -198, -698, 136, -316, 
		174, 262, 236, -76, 832, -769, -609, -550, -669, -298, 
		-491, 25, -168, -879, 197, 143, 792, 455, 786, 294, 
		754, 458, -952, -715, 964, 420, -480, 211, -619, 678, 
		-728, 912, -486, 708, -809, -586, -609, 328, -961, 187, 
		787, -382, 994, 593, 240, -134, 313, 512, -671, 221,
	};

---------------------------------------

Unique random number generator

Öyle bir rastgele sayı üreticisi gerekiyor ki, özellikle oyun programlarında çok ihtiyaç oluyor, her ürettiği sayı unique olacak.

Buradaki kritik nokta, urand fonksiyonu bir sayının daha önce üretilmiş veya üretilmemiş olduğunu nasıl anlayacak.

Bunu bilmesinin tek yolu bu değerleri bir veri yapısında, örneğin bir dizide tutması.

int a[URAND_MAX] = { 0 };

Başlangıçta dizinin bütün elemanları 0, buradaki 0 bir bayrak değeri olsun. Örneğin bu dizinin 56 indisli elemanı 0 ise, 56 henüz üretilmemiş olsun ama o dizinin 56 indisli elemanı 1 ise, üretilmiş olsun.
Yani dizinin her bir elemanı ya 0 ya da 1 olacak. 

Dolayısıyla bu look-up table'ı, bu diziyi kullanarak herhangi bir sayının üretilip üretilmediğini anlayabiliriz.

Yalnız bu dizinin statik ömürlü olması gerekiyor. Mesela bu dizinin 15 indisli elemanının değerini değiştirsek, bu fonksiyon bir kez daha çağrıldığında otomatik ömürlü olduğu için bütün elemanları 0 değeriyle hayata gelir.

Bu yüzden otomatik ömürlü değil, statik ömürlü olması gerekiyor. Bu da iki yol ile mümkün. Ya global bir dizi olacak, ya da statik bir yerel dizi olacak.

Global dizi olması, bu diziye tüm kaynak dosyadaki fonksiyonların erişmesi demek. Bu da çok riskli, tehlikeli, test etmeyi de zorlaştırıyor.

Oysa bu dizi, bizim fonksiyonumuzun implementasyonuyla ilgili tamamen. Yani başka hiçbir kodu ilgilendirmiyor, o yüzden bunu global yapmak sentaks hatası olmasa da, tercih edilmemesi gerekir.

Eğer bir varlık sadece bir fonksiyonunun implementasyonunda kullanılacaksa, diğer fonksiyonların o varlığa erişimi gerekmiyorsa, kesinlikle onu global yapmamalıyız.

static int a[URAND_MAX] = { 0 };

count isminde bir değişkenle de bu noktaya kadar kaç tane rastgele sayı üretildiği bilgisini tutacağız. Bu varlığın da statik ömürlü olması gerekir.

static int count = 0;

Her üretilen sayı için count'ı bir arttırdığımıza göre, count'un değeri URAND_MAX olduğunda, artık üretilecek başka bir sayı yok.
Rastgele sayı üretmeden önce bunu sınamalıyız, ki böyleyse, fonksiyon çağrılmaması gereken bir durumda çağrılmış. -1 Hata kodu değerini döndürüyoruz.

En azından, üretilecek en az 1 tane rastgele sayı var. Üretilecek rastgele sayıyı tutan bir val isminde bir değişken tanımladık.

Bir sonsuz döngü içinde val isimli değişkene 0 ile URAND_MAX arasında bir değer atıyoruz ve val'e atanan değer unique mi değil mi kontrol ediyoruz.

-----

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define URAND_MAX 10

//urand işlevi, 0 dahil, URAND_MAX hariç aralıkta rastgele değer üretecek.
//ancak ürettiği sayıyı tekrar üretmeyecek.
//bu durumda bu işlev en fazla URAND_MAX kez çağrılabilir.
//fonksiyon daha fazla kez çağrılırsa hata kodu olarak -1 değerini döndürecek.

int urand(void)
{
	static int a[URAND_MAX] = { 0 };
	static int count = 0;
	int val;

	if (count == URAND_MAX)
		return -1;
	
	for (;;) {
		val = rand() % URAND_MAX;
		if (a[val] == 0)
			break;
	}

	++count;
	a[val] = 1;
	return val;
}

int main()
{
	randomize();
	for (int i = 0; i < URAND_MAX; ++i) {
		printf("%d ", urand());
	}

	printf("\n");
	printf("%d ", urand()); // burada -1 değeri yazdırılmalı çünkü artık üretilecek rastgele bir sayı yok.
}

---------------------------------------

Sonsuz for döngüsü deyimini aşağıdaki gibi yazabilirdik.

	//Atama operatörüyle oluşturulan bir ifadenin değeri nesneye atanan değeridir. 
	//Köşeli parantezin içindeki ifadenin değeri val'e atanan değerdir. 
	//While parantezi içindeki ifade lojik yorumlamaya tabi tutulduğuna göre, non zero olduğu sürece döngü dönecek, döngüden çıkması için a dizisinin val indisli elemanının 0 olması gerekecek. 

	while (a[val = rand() % URAND_MAX]); 
		;

---------------------------------------

sizeof operatörü

Bu operatörünün atomu bir anahtar sözcük. Dilin 45 tane operatörlerinden biri, diğer hiçbir anahtar sözcük operatör olarak kullanılamıyor.

sizeof operatörüyle oluşturulmuş bir ifade, çoğu zaman bir fonksiyon çağrısını andırdığı için fonksiyon olarak algılanabiliyor. Bu bir fonksiyon değil, C dilinin bir operatörü.

sizeof operatörü bir compile-time operatörüdür. Yani bu operatörün ürettiği değeri, derleyici derleme zamanında hesaplıyor. Run-time ile hiçbir alakası yok.

sizeof operatörüyle oluşturulan ifade, bir sabit ifadesidir. constant expression (VLA dahil değil)

operatör öncelik tablosunda 2. öncelik seviyesinde. Farklı kullanım biçimleri olsa da, hepsinin ortak tarafı şu.

Bir tür için bellek alanının ihtiyacının kaç byte olduğu değeri. Örnek olarak int türden bir nesne kaç byte yer kaplıyor.

sizeof operatörünün ürettiği değer bir tam sayı değeri fakat işaretli int türünden değil. İşaretsiz bir tam sayı. Derleyiciye bağlı eş isim olarak size_t ismi de kullanılıyor.

unsigned int - unsigned long int - unsigned long long int türlerinden biri.

------

sizeof operatörünün operandının bir tür olması. Bu durumda parantez zorunlu. Yani parantez operatörün sentaksının bir bileşeni.

sizeof(int)

#include <stdio.h>

int main()
{
	printf("size of a char = %zu\n", sizeof(char));
	printf("size of a short = %zu\n", sizeof(short));
	printf("size of a int = %zu\n", sizeof(int));
	printf("size of a long = %zu\n", sizeof(long));
	printf("size of a long long = %zu\n", sizeof(long long));
	printf("size of a float = %zu\n", sizeof(float));
	printf("size of a double = %zu\n", sizeof(double));
	printf("size of a long double = %zu\n", sizeof(long double));
}

------

sizeof operatörünün oluşturduğu ifade sabit ifadesidir.

Mesela aşağıdaki ifade sentaks hatasıdır.

int x = 10;

int a[x] = { 0 }; //sentaks hatası

Ancak aşağıdaki ifade sentaks hatası değildir.

int x = 10;

int a[sizeof(double)] = { 0 };

Switch veya case ifadeleri gibi sabit ifadesi beklenen yerlerde sizeof operatörünün ürettiği değerden faydalanabiliriz.

------

sizeof operatörünün operandı herhangi bir ifade olabilir. 

sizeof(expression) -> burada operand olan ifadenin parantez içine alınması zorunlu değil. Tabi operatör önceliğine dikkat edilmesi lazım.

sizeof exp
sizeof (exp)

Eğer sizeof operatörü operand olarak ifade alırsa derleyici derleme zamanında bu ifadenin türüne bakıyor. 
Bu ifadenin türü neyse o türün sizeof değerini derleme zamanı sabiti olarak üretiyor.

Aşağıdaki örnekte ifadenin parantez içerisinde olması veya olmamasının bir farkı yok.

int main()
{
	int x = 10;
	double dval = 2.3;

	printf("%zu\n", sizeof x);
	printf("%zu\n", sizeof (x));
}

------

#include <stdio.h>

int main()
{
	int x = 10;
	double dval = 2.3;

	printf("%zu\n", sizeof x);
	printf("%zu\n", sizeof (x));
	printf("%zu\n", sizeof (x + .5));
	
	printf("%zu\n", sizeof 'A'); 		//Karakter sabitlerinin türü int ->> 4
	printf("%zu\n", sizeof 'A' + 5);	//sizeof daha öncelikli. bu ifade sizeof 'A' + 5 ->> 9
	printf("%zu\n", sizeof ('A' + 5));  //Parantez içideki ifadenin değeri int. ->> 4
}

------

sizeof operatörünün operandı olan ifade için derleyici işlem kodu üretmez.
Böyle durumlara programlamada unevaluated context deniliyor.
C dilinde sadece burada var. C++ da bir çok yerde var.
Belirli ifadelerin belirli contextde işlem kodu üretmemesi gerekiyor. C dilinde bu sadece sizeof operatörünün operandı için geçerlidir.

#include <stdio.h>

int main()
{
	int x = 15;

	printf("%zu\n", sizeof(x++)); 	// ->> 4
	printf("%d\n", x);				// ->> 15
}

------

#include <stdio.h>

int foo(){
	printf("foo cagrildi!\n");
	return 1;
}

int main()
{
	unsigned int x = sizeof(foo()); //derleyici foo() için işlem kodu üretmeyecek.
	printf("x = %u\n", x);
}

------

Ayrıca aşağıdaki kodda herhangi bir tanımsız davranış yok. Çünkü sizeof operatörünün operandı olan ifade için derleyici bir işlem kodu üretmeyecek.

#include <stdio.h>

int main()
{
	int x;
	sizeof(x + 1.2);
}

------

sizeof operatörünün operandı bir dizi ismi olduğunda array to pointer conversion ya da array decay uygulanmıyor.
(Bir dizinin isminin bir ifade içerisinde kullanılması durumunda, derleyicinin bunu dizinin ilk elemanının adresine dönüştürmesi.)
Bunun iki tane istisnası var. Birisi sizeof operatörünün operandı olması.

#include <stdio.h>

int main()
{
	int a[10] = { 0 }; //10elemanlı, 4 byte -> Bellekte 40byte'lık bir yer kaplayacak.
	printf("%zu\n", sizeof a);
}

------

#include <stdio.h>

int main()
{
	int a[10] = { 0 }; 
	printf("%zu\n", sizeof a[0]); //Derleyici bu indisteki elemanın türüne bakıyor. int türü olduğu için 4 çıktısını göreceğiz.
}

------

C'nin en sık kullanılan yapılardan biri. Bir dizinin boyutunu derleme zamanında elde etmenin standart, en çok kullanılan yolu budur.

sizeof a 	-> bu dizi bellekte kaç byte yer kaplıyor.
sizeof a[0] -> bu indisteki eleman bellekte kaç byte yer kaplıyor.

sizeof a / sizeof a[0] ->>> Dizinin Boyutu

#include <stdio.h>

int main()
{
	int a[10] = { 0 }; 
	printf("%zu\n", sizeof a / sizeof a[0]);
}

------

#include <stdio.h>

int main()
{
	int a[10] = { 0 };
	double b[20] = { 0. };
	char c[240] = { 0 };

	printf("boyut a = %zu\n", sizeof (a) / sizeof(a[0]));
	printf("boyut b = %zu\n", sizeof (b) / sizeof(b[0]));
	printf("boyut c = %zu\n", sizeof (c) / sizeof(c[0]));
}

------

Yalnız bazı noktalara dikkat etmemiz gerekiyor. Bunların hepsi birer sabit ifadesidir. Yani programın çalışma zamanında hesaplanan değerler değildir.

------

#include <stdio.h>

int main()
{
	int a[] = {1, 3, 5, 7, 9, 12, 56};

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i){
		printf("%d ", a[i]);
	}
}

------

Bu yapıyı sık sık yazmak yerine bunu bir fonksiyonel makro haline getirebiliriz. dutility.h başlık dosyasında tanımladım.

#define asize(x)        (sizeof(x) / sizeof(x[0]))

#include <stdio.h>
#include "dutility.h"

int main()
{
	int a[] = {1, 3, 5, 7, 9, 12, 56};

	for (int i = 0; i < asize(a); ++i){
		printf("%d ", a[i]);
	}
}

------

sizeof operatörünün ürettiği değer unsigned int. makromuza baktığımız zaman iki ifadenin de unsigned int olduğunu görüyoruz.

makro: #define asize(x)        (sizeof(x) / sizeof(x[0]))

unsigned int ile int'i işleme sokarsak, işlem unsigned int olacaktır. 

asize(a) - 2 -> bu ifadenin değeri 3 fakat unsigned int türden 3.

i < 3 -> i'nin türü ise işaretli int. aynı tam sayı türü işleme sokulduğunda işlem unsigned int olur.

i'nin değeri -2, karşılaştırma işlemine tabi tutulduğunda işlem unsigned türden yapılacak. 

unsigned	4294967294
signed		-2

Aslında burada karşılaştırılan değerler 4294967294 > 3 
Döngü koşulu sağlanamadığı için döngünün içine girilmeyecek.

#include <stdio.h>
#include "dutility.h"

int main()
{
	int a[] = {1, 2, 3, 4, 5};

	for (int i = -2; i < asize(a) - 2; ++i){
		printf("%d ", a[i + 2]);
	}
}

------

Dizilerin boyutlarının başka dizilerin boyutlarıyla ilişkili hâle getirilmesi. C'de çok sık kullanılan bir idiom.

#include <stdio.h>
#include "dutility.h"

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[asize(a) * 2];
	int c[asize(b) * 3 / 2];

	printf("%zu\n", asize(a));
	printf("%zu\n", asize(b));
	printf("%zu\n", asize(c));
}

------

Bu operatörün operandı olan ifade için işlem kodu üretilmiyor.

sizeof x + 5
sizeof (x + 5)

------

#include <stdio.h>

int main()
{
	int y = 5;
	int a = 3;

	sizeof ++y + ++a; //sizeof ++y = 4 ->>> 4 + 4 = 8
}

------

Merge (Sıralı Birlestirme)

Aynı sıralama kriteriyle sıralanmış iki tane sıralı dizimiz olsun. Ve bunu 3. bir dizide sıralı olarak birleştirmek O(n) karmaşıklığında bir algoritma.

Array A: 41 169 334 358 464 467 478 500 724 962 
Array B: 145 281 436 491 705 827 827 942 961 995 

Öyle bir kod yazacağız ki C dizisi, A ve B'nin birleşimi olacak ve C dizisinde de sıra bozulmayacak.

//Dizileri kontrol ediyoruz dizinin elemanları bitmiş mi diye. A dizisi bitmişse B'den yazdık. B dizisi bitmişse A'dan yazdık.

#include <stdio.h>
#include "dutility.h"

#define SIZE 10

int main()
{
	int a[SIZE];
	int b[SIZE];
	int c[SIZE + SIZE];

	randomize();

	set_random_array(a, SIZE);
	set_random_array(b, SIZE);
	
	sort_array(a, SIZE);
	sort_array(b, SIZE);
	
	print_array(a, SIZE);
	print_array(b, SIZE);

	int idx_a = 0;
	int idx_b = 0;

	for (int i = 0; i < 2 * SIZE; ++i){
		if (idx_a == SIZE) {			
			c[i] = b[idx_b++];
		}
		else if (idx_b == SIZE) {
			c[i] = a[idx_a++];
		}
		else if (a[idx_a] < b[idx_b])
			c[i] = a[idx_a++];
		else
			c[i] = b[idx_b++];	
	}

	print_array(c, SIZE * 2);
}

------

C dilinde aşağıdaki kodda, a[i] yazmak ile i[a] yazmak arasında bir fark yok. Dilin kuralı bu şekilde, herhangi bir tanımsız davranış yok. Pointerlar ile ilgili.

#include <stdio.h>

int main()
{
	int a[10] = {5, 17, 22, 8, 4, 15, 78, 112, 48, 24};

	for (int i = 0; i < 10; ++i) {
		printf("%d %d\n", a[i], i[a]);
	}
}

*/

