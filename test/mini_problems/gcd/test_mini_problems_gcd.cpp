#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "algorithm.h"
#include "test_utils.h"

#include "gcd_bruteforce.cpp"
#include "gcd_euclide.cpp"
#include "gcd_euclide_iterative.cpp"
#include "gcd_euclide_pre_cpp11.cpp"
#include "gcd_euclide_cpp11.cpp"

TEST(gcd, example1)
{
  constexpr int x = 35, y = 28;
  constexpr int expected = 7;
  ASSERT_EQ(expected, gcd_bruteforce(x, y));
  ASSERT_EQ(expected, gcd_bruteforce(y, x));

  ASSERT_EQ(expected, gcd_euclide(x, y));
  ASSERT_EQ(expected, gcd_euclide(y, x));

  ASSERT_EQ(expected, gcd_euclide_iterative(x, y));
  ASSERT_EQ(expected, gcd_euclide_iterative(y, x));

  constexpr auto cpp11ans = GCDEuclidePreCpp11<x, y>::gcd;
  ASSERT_EQ(expected, cpp11ans);
}

TEST(gcd, example1_mod)
{
  constexpr int x = 35, y = 25;
  constexpr int expected = 5;
  ASSERT_EQ(expected, gcd_bruteforce(x, y));
  ASSERT_EQ(expected, gcd_bruteforce(y, x));

  ASSERT_EQ(expected, gcd_euclide(x, y));
  ASSERT_EQ(expected, gcd_euclide(y, x));

  ASSERT_EQ(expected, gcd_euclide_iterative(x, y));
  ASSERT_EQ(expected, gcd_euclide_iterative(y, x));

  constexpr auto cpp11ans = GCDEuclidePreCpp11<x, y>::gcd;
  ASSERT_EQ(expected, cpp11ans);
}

TEST(gcd, example2)
{
  constexpr int x = 15, y = 8;
  constexpr int expected = 1;
  ASSERT_EQ(expected, gcd_bruteforce(x, y));
  ASSERT_EQ(expected, gcd_bruteforce(y, x));

  ASSERT_EQ(expected, gcd_euclide(x, y));
  ASSERT_EQ(expected, gcd_euclide(y, x));

  ASSERT_EQ(expected, gcd_euclide_iterative(x, y));
  ASSERT_EQ(expected, gcd_euclide_iterative(y, x));

  constexpr auto cpp11ans = GCDEuclidePreCpp11<x, y>::gcd;
  ASSERT_EQ(expected, cpp11ans);
}

TEST(gdc, random_generated)
{
  std::vector<std::pair<int, int>> P = {
      {12971, 23915}, {27117, 1366},  {28899, 18122}, {23161, 17061},
      {28049, 29173}, {26861, 164},   {2422, 19248},  {17154, 25788},
      {26108, 499},   {13160, 3103},  {29137, 11157}, {4449, 9137},
      {8501, 1872},   {22850, 13064}, {13153, 25573}, {1846, 8430},
      {18702, 14991}, {13628, 5989},  {24603, 18475}, {23809, 28508},
      {16396, 30292}, {14923, 15567}, {29582, 13642}, {7687, 19439},
      {2302, 3724},   {21692, 19304}, {7162, 29071},  {21694, 10750},
      {6927, 9147},   {12165, 20926}, {18918, 5191},  {26497, 4417},
      {9104, 7132},   {8125, 27456},  {18798, 16756}, {31035, 9757},
      {11589, 8144},  {18719, 25186}, {8765, 32092},  {24638, 21105},
      {4928, 6383},   {12260, 19086}, {30578, 13822}, {1125, 2874},
      {4002, 2520},   {1515, 32681},  {9488, 14682},  {8710, 31285},
      {16650, 20452}, {25524, 5906},  {22784, 10418}, {30513, 25476},
      {23953, 18801}, {13575, 9169},  {25730, 26961}, {16171, 19995},
      {7988, 14057},  {5705, 25534},  {23727, 23372}, {26543, 29750},
      {28257, 18820}, {22946, 25663}, {21566, 4609},  {1409, 12552},
      {20528, 25273}, {13172, 11182}, {6901, 7430},   {11819, 21951},
      {23431, 12802}, {503, 18940},   {16016, 3740},  {18787, 29916},
      {14363, 15290}, {17473, 11868}, {5475, 16601},  {16437, 15152},
      {10382, 5945},  {20744, 27814}, {18074, 29343}, {28263, 32400},
      {7043, 26311},  {8514, 19},     {14975, 24060}, {4722, 22538},
      {3054, 17561},  {6715, 8601},   {31898, 18106}, {17059, 1339},
      {28262, 12953}, {22108, 10891}, {8563, 22899},  {398, 12932},
      {4626, 21072},  {15348, 26524}, {26557, 31693}, {28966, 31606},
      {2845, 27436},  {19233, 20289}, {14709, 32402}, {4850, 19786},
      {17695, 18474}, {31947, 3435},  {8196, 17619},  {11839, 1775},
      {4472, 26038},  {22231, 10317}, {32666, 13958}, {25661, 18292},
      {31670, 16840}, {20112, 1153},  {32028, 26829}, {31662, 876},
      {11108, 28194}, {18675, 30101}, {9873, 7843},   {26973, 26548},
      {28749, 15793}, {29842, 974},   {31673, 18297}, {28600, 6534},
      {14894, 18116}, {14724, 22214}, {21721, 29125}, {30684, 11566},
      {3158, 14105},  {22340, 17935}, {3709, 29357},  {20597, 11953},
      {12159, 28188}, {20692, 29939}, {27653, 19423}, {28778, 2557},
      {7411, 30123},  {147, 2331},    {1225, 6150},   {13780, 19036},
      {24348, 8456},  {812, 31922},   {12022, 6041},  {3334, 16139},
      {11741, 22960}, {14584, 15789}, {26176, 22047}, {44, 15694},
      {29947, 5275},  {19831, 31816}, {23023, 9728},  {27990, 30519},
      {7535, 2198},   {18719, 6410},  {8063, 30649},  {3533, 14008},
      {25924, 32660}, {23515, 12843}, {30451, 28317}, {1029, 32676},
      {3942, 3822},   {30956, 31487}, {32552, 11434}, {7929, 11092},
      {23762, 23183}, {24977, 31865}, {23755, 19869}, {1132, 31957},
      {27031, 7536},  {13373, 9581},  {2120, 9253},   {28340, 5141},
      {20518, 26066}, {13313, 4753},  {30272, 29794}, {11100, 702},
      {28734, 25737}, {25629, 24912}, {15118, 16718}, {17565, 20313},
      {7143, 26644},  {18344, 8179},  {4830, 17562},  {31060, 1708},
      {21138, 30336}, {9786, 2144},   {15457, 21549}, {28357, 13974},
      {18123, 24117}, {18283, 7726},  {29061, 15562}, {5304, 77},
      {31672, 19043}, {28905, 22113}, {8742, 24310},  {30531, 22766},
      {20385, 2874},  {6331, 22004},  {22527, 6264},  {23836, 10062},
      {30474, 22481}, {19406, 22273}, {844, 6568},    {27843, 19396},
      {987, 18942},   {3365, 2652},   {10581, 26197}, {22430, 16523},
      {16493, 8925},  {32396, 29376}, {5378, 15672},  {19328, 25214},
      {24047, 29800}, {13822, 30859}, {9580, 31892},  {29910, 21506},
      {30519, 20570}, {13885, 18218}, {28575, 22373}, {4678, 24274},
      {437, 29655},   {3931, 29445},  {28868, 15573}, {29242, 24072},
      {23007, 24039}, {24756, 28838}, {14444, 7334},  {30430, 22653},
      {29870, 11246}, {30708, 5987},  {15288, 3877},  {22131, 26819},
      {4368, 5628},   {5088, 8523},   {11611, 25622}, {14003, 4064},
      {31072, 27418}, {21618, 8293},  {17523, 2884},  {17347, 9929},
      {30334, 25371}, {11842, 23198}, {26727, 14160}, {10485, 10191},
      {123, 9126},    {18793, 12051}, {28125, 22819}, {32724, 32461},
      {24260, 2997},  {26270, 23161}, {1269, 30047},  {25658, 20820},
      {8457, 11764},  {11558, 4798},  {32457, 23816}, {16599, 29485},
      {1293, 7998},   {24833, 806},   {8952, 30392},  {5799, 13070},
      {29275, 13036}, {24843, 18503}, {30682, 17107}, {14099, 4189},
      {5370, 7108},   {6749, 9784},   {577, 19273},   {5038, 25960},
      {12488, 1807},  {4402, 25584},  {1903, 13313},  {24805, 6077},
      {121, 25662},   {17724, 25265}, {15143, 17509}, {4547, 4455},
      {30342, 20920}, {12963, 15036}, {28949, 23099}, {16066, 19787},
      {7248, 7590},   {16649, 5553},  {19352, 12988}, {9994, 4504},
      {19082, 4871},  {1602, 2668},   {1917, 2699},   {5618, 29256},
      {514, 23313},   {30311, 7791},  {8306, 12086},  {20786, 20639},
      {19732, 21228}, {9200, 4079},   {8948, 4736},   {17595, 14588},
      {26245, 17504}, {32535, 26327}, {6114, 6183},   {2286, 31332},
      {8429, 12199},  {10553, 19945}, {15908, 7127},  {3753, 18823},
      {4770, 2368},   {20967, 24759}, {5653, 17005},  {9264, 27681},
      {14476, 4071},  {24973, 30211}, {23132, 31552}, {19060, 21534},
      {177, 16013},   {13957, 9318},  {24385, 10013}, {20660, 1102},
      {21122, 14446}, {7738, 24331},  {9097, 24808},  {23676, 13145},
      {17327, 22483}, {9787, 3127},   {29904, 16285}, {19767, 23456},
      {22950, 29489}, {24751, 2538},  {16190, 24959}, {1809, 1478},
      {26771, 31321}, {2049, 4459},   {5525, 3139},   {30840, 14472},
      {1981, 19667},  {28690, 16651}, {25732, 27952}, {24026, 24460},
      {4630, 11810},  {26943, 31733}, {4358, 20779},  {31093, 14101},
      {2867, 7180},   {17783, 31214}, {21223, 14407}, {23727, 15504},
      {21089, 18958}, {28477, 16704}, {21650, 24336}, {28393, 12378},
      {16564, 29591}, {13354, 7510},  {24227, 2867},  {29536, 9842},
      {24587, 18322}, {507, 25919},   {31562, 1984},  {4823, 8298},
      {27855, 21012}, {29481, 7776},  {10931, 15588}, {695, 9408},
      {10838, 10973}, {7883, 11431},  {29674, 28125}, {13246, 21639},
      {1585, 27845},  {2380, 31675},  {2192, 3343},   {18568, 154},
      {9879, 9961},   {11649, 8930},  {8617, 11241},  {22161, 18398},
      {24248, 31876}, {5480, 1656},   {21884, 9981},  {8633, 1070},
      {16504, 24353}, {21391, 1498},  {3466, 25524},  {3773, 21693},
      {9654, 9024},   {29715, 30502}, {6260, 21510},  {20733, 8762},
      {32173, 30708}, {22274, 7470},  {3675, 17087},  {30035, 1281},
      {26447, 28470}, {4439, 16008},  {14907, 6466},  {11108, 6231},
      {21642, 17638}, {15095, 11759}, {1449, 29204},  {22114, 19985},
      {20356, 22131}, {11870, 8753},  {18308, 1997},  {4084, 14798},
      {4224, 15337},  {21178, 16494}, {26642, 20387}, {4537, 24090},
      {14463, 21913}, {1192, 12436},  {27079, 16092}, {410, 18813},
      {22774, 28968}, {23630, 28078}, {30645, 11164}, {16436, 5625},
      {7520, 31096},  {2188, 17572},  {12279, 12223}, {1966, 17833},
      {8451, 28349},  {4346, 979},    {30036, 14978}, {26476, 31741},
      {11198, 4946},  {15068, 31520}, {8296, 30530},  {30066, 27740},
      {18344, 11242}, {17829, 17217}, {24538, 11857}, {29852, 31856},
      {18510, 30944}, {4934, 7334},   {19974, 9581},  {28392, 26879},
      {27931, 2417},  {18510, 6264},  {5294, 902},    {26514, 16941},
      {25420, 12787}, {12297, 28005}, {9287, 29301},  {15441, 20527},
      {387, 1572},    {23124, 32487}, {25871, 8735},  {13066, 9766},
      {22876, 31437}, {15718, 13182}, {16494, 6160},  {30095, 4157},
      {9674, 20080},  {32387, 11624}, {18859, 11992}, {22097, 11961},
      {5285, 20900},  {124, 27666},   {22304, 11353}, {20705, 28452},
      {30162, 5932},  {11616, 31575}, {25117, 24349}, {8441, 26652},
      {10769, 22264}, {17927, 11806}, {15108, 3481},  {19111, 31782},
      {1968, 13340},  {29243, 26891}, {29206, 15240}, {6279, 19665},
      {5867, 2571},   {11159, 22751}, {28537, 4344},  {32265, 13066},
      {3025, 100},    {12183, 9607},  {12980, 9199},  {8710, 20073},
      {29115, 29873}, {25132, 2545},  {2742, 6720},   {27128, 18504},
      {14067, 5960},  {8091, 5350},   {13044, 20379}, {20803, 24444},
      {13357, 3254},  {2970, 22113},  {31214, 28214}, {30820, 9130},
      {21670, 4315},  {26589, 3703},  {29230, 29365}, {15472, 14266},
      {32257, 29455}, {14645, 32220}, {12314, 13960}, {29108, 19983},
      {19441, 20891}, {24169, 22907}, {21771, 32448}, {10801, 20609},
      {9892, 5856},   {20002, 21004}, {4876, 18757},  {2774, 3870},
      {18830, 29302}, {25067, 18007}, {13585, 4753},  {26884, 6793},
      {30061, 5539},  {32149, 18143}, {1668, 28221},  {5813, 28611},
      {23454, 28644}, {6914, 28323},  {18370, 8078},  {10875, 19656},
      {22933, 16560}, {7804, 1760},   {4838, 13243},  {2105, 1380},
      {6497, 3065},   {28870, 7392},  {15357, 22166}, {21386, 11712},
      {22422, 9381},  {13109, 2671},  {329, 28692},   {6400, 1738},
      {11072, 6156},  {27515, 22943}, {8629, 14959},  {3096, 8393},
      {20078, 26325}, {17317, 5500},  {3598, 28868},  {10390, 14323},
      {13790, 28882}, {32361, 11169}, {10377, 29846}, {12219, 15434},
      {27047, 8897},  {3845, 2047},   {20118, 24093}, {12899, 3724},
      {10951, 16733}, {10064, 8574},  {13669, 6719},  {8927, 13755},
      {17714, 1275},  {19135, 8050},  {31116, 1050},  {4007, 22241},
      {31981, 1678},  {31241, 12467}, {20430, 14319}, {7182, 7106},
      {13026, 25015}, {2824, 3510},   {29417, 9681},  {5653, 5549},
      {22122, 3492},  {1809, 13427},  {8607, 21044},  {28407, 18194},
      {25809, 29022}, {15717, 16722}, {6537, 28419},  {6768, 12417},
      {18869, 11281}, {21310, 14871}, {24524, 18419}, {956, 24661},
      {25581, 18826}, {30942, 6249},  {1000, 32766},  {14848, 28246},
      {22950, 8052},  {28618, 3151},  {27183, 1220},  {30354, 32444},
      {7242, 29485},  {29242, 3166},  {22091, 23162}, {29815, 27394},
      {28672, 19917}, {24437, 3604},  {2382, 18185},  {30520, 14000},
      {19177, 23603}, {23421, 27518}, {4137, 8816},   {29107, 7612},
      {23683, 20976}, {8509, 16817},  {19723, 27653}, {22034, 31188},
      {18134, 18821}, {30880, 15792}, {24229, 2180},  {4780, 32518},
      {21208, 13337}, {16526, 4811},  {14273, 25043}, {28267, 669},
      {24774, 24720}, {26702, 17688}, {27926, 31373}, {875, 16038},
      {13309, 12736}, {31806, 27900}, {1273, 31400},  {5617, 24458},
      {28383, 15033}, {13566, 6929},  {523, 27574},   {15132, 11742},
      {5065, 22383},  {28047, 26512}, {28139, 19050}, {5287, 30564},
      {9445, 7823},   {17110, 7766},  {10402, 6834},  {21455, 18712},
      {15181, 22565}, {11017, 14427}, {12073, 9290},  {21751, 18610},
      {23320, 25456}, {5674, 31502},  {6436, 1072},   {2204, 27453},
      {3931, 22441},  {17918, 14051}, {30911, 10254}, {18358, 10540},
      {12296, 14697}, {2343, 31763},  {25881, 29728}, {7618, 13516},
      {2088, 5635},   {4053, 32234},  {22413, 22288}, {9672, 26112},
      {98, 24877},    {18700, 12747}, {12110, 24256}, {17084, 29094},
      {26738, 9121},  {1715, 25576},  {19442, 22721}, {11351, 29222},
      {18001, 13311}, {28152, 25588}, {14289, 27482}, {2376, 6229},
      {30820, 16044}, {25152, 20319}, {26559, 23839}, {25464, 18189},
      {7954, 26632},  {17843, 21438}, {19303, 20383}, {15651, 30735},
      {22890, 13378}, {28714, 12480}, {15224, 11225}, {21544, 13349},
      {19679, 16273}, {27330, 16676}, {31712, 10998}, {23803, 29357},
      {28704, 5221},  {30106, 9243},  {3255, 22787},  {32423, 20635},
      {28596, 8269},  {8649, 22145},  {23545, 16331}, {22606, 15736},
      {2269, 15939},  {16333, 17468}, {12260, 20131}, {1281, 5330},
      {22254, 10549}, {23354, 19134}, {15974, 25001}, {17046, 27642},
      {1172, 15449},  {26991, 18046}, {237, 11089},   {12621, 7801},
      {9569, 23513},  {20948, 4943},  {22791, 27267}, {105, 8382},
      {7144, 12662},  {20761, 27028}, {14902, 7078},  {3838, 26914},
      {32482, 22124}, {20443, 31083}, {21553, 28403}, {13341, 15469},
      {17323, 18793}, {12055, 14178}, {13121, 23909}, {32078, 29565},
      {1411, 14023},  {18412, 8144},  {32385, 7413},  {11444, 23896},
      {29416, 29608}, {24204, 22220}, {479, 11786},   {7946, 643},
      {31627, 13285}, {9549, 27598},  {10049, 7622},  {16560, 24202},
      {26276, 26308}, {29051, 22208}, {31420, 15858}, {1188, 21811},
      {16431, 5543},  {14334, 10155}, {20249, 20042}, {13913, 14936},
      {27223, 8918},  {23549, 13708}, {20905, 22135}, {18445, 1933},
      {1585, 9528},   {4266, 20314},  {31516, 22575}, {31456, 3094},
      {18821, 28188}, {15369, 9357},  {30750, 13395}, {1970, 5789},
      {11688, 28417}, {26707, 8794},  {12424, 17344}, {19859, 32103},
      {17935, 4816},  {588, 21856},   {21436, 31941}, {13597, 7450},
      {3640, 31622},  {20042, 17041}, {15343, 24026}, {15826, 5907},
      {21372, 1991},  {4803, 6836},   {258, 18221},   {13428, 7164},
      {9101, 22693},  {2172, 20858},  {19243, 26905}, {22431, 10662},
      {27872, 8842},  {30340, 3646},  {18205, 11958}, {17227, 23875},
      {3746, 31105},  {3166, 10744},  {20433, 8183},  {543, 2558},
      {24566, 19214}, {6031, 3602},   {31410, 17681}, {28026, 7830},
      {6083, 23032},  {19357, 30918}, {4362, 12391},  {1289, 27081},
      {31218, 17401}, {13865, 19018}, {9428, 24290},  {24426, 14288},
      {5109, 26568},  {3653, 3611},   {13631, 16835}, {18675, 1934},
      {27438, 32635}, {21707, 2776},  {9986, 19112},  {28443, 24991},
      {15806, 10084}, {26210, 12879}, {31034, 23585}, {18300, 22947},
      {20091, 22015}, {2504, 19022},  {25304, 23486}, {9193, 9046},
      {2438, 11409},  {239, 12005},   {21078, 18134}, {22533, 26485},
      {32712, 21782}, {29332, 30001}, {31384, 28806}, {27523, 31200},
      {26507, 7786},  {23174, 11989}, {18942, 32596}, {12459, 5458},
      {8772, 23368},  {4333, 13798},  {31684, 20142}, {3444, 17400},
      {12137, 16288}, {17784, 17792}, {15786, 20874}, {4761, 17971},
      {8910, 15933},  {17388, 6680},  {1474, 19786},  {8709, 25981},
      {6401, 23338},  {1898, 21846},  {26385, 8188},  {22035, 30956},
      {5710, 23893},  {12318, 20359}, {20236, 8704},  {3056, 30624},
      {652, 12774},   {25770, 20458}, {24908, 8727},  {22054, 17739},
      {5741, 27002},  {26660, 11109}, {25299, 6229},  {30121, 21113},
      {9866, 17389},  {29063, 30046}, {24624, 16273}, {32766, 14957},
      {29420, 589},   {5272, 8829},   {30919, 15463}, {7193, 13000},
      {26252, 21151}, {15209, 2968},  {3834, 4426},   {10100, 518},
      {10013, 31111}, {6619, 14721},  {27788, 2962},  {11031, 6370},
      {12357, 27723}, {18686, 8071},  {32751, 32202}, {25412, 19305},
      {12335, 24636}, {27865, 3538},  {3355, 17791},  {31884, 15583},
      {22719, 3372},  {5549, 1954},   {31686, 29879}, {17098, 31696},
      {27817, 19830}, {30480, 32096}, {32168, 15899}, {7434, 24207},
      {8802, 1913},   {6921, 14335},  {24983, 2447},  {13125, 12831},
      {21954, 27396}, {29242, 16390}, {21098, 14854}, {24509, 15825},
      {23280, 1516},  {19977, 27949}, {14077, 23402}, {30099, 5412},
      {27801, 17857}, {27601, 24042}, {17038, 14809}, {5684, 32213},
      {24771, 4685},  {27198, 194},   {19752, 6122},  {707, 13183},
      {10076, 11911}, {9766, 3673},   {31384, 863},   {9886, 9879},
      {31724, 1772},  {32512, 22585}, {8388, 6321},   {5167, 27980},
      {29040, 3162},  {13541, 12997}, {9787, 5890},   {5353, 28671},
      {22468, 21269}, {13144, 12604}, {8803, 2651},   {25886, 26402},
      {19988, 32650}, {24709, 6065},  {11092, 11890}, {21643, 4541},
      {10436, 29032}, {16037, 30169}, {14448, 20651}, {23686, 27544},
      {6577, 30141},  {1460, 15562},  {14152, 20960}, {8713, 28950},
      {21071, 30978}, {157, 12246},   {2835, 16375},  {23643, 3176},
      {1390, 26806},  {11217, 19129}, {15410, 683},   {13363, 24783},
      {31666, 7455},  {24720, 24230}, {29074, 8189},  {31671, 3935},
      {24163, 19340}, {8189, 2794},   {15150, 3325},  {17254, 17222},
      {12912, 25087}, {28778, 13256}, {30464, 8209},  {26520, 19456},
      {17014, 28921}, {24631, 32276}, {24166, 22765}, {2475, 342},
      {16228, 32196}, {12991, 25862}, {18020, 30171}, {16225, 27518},
      {1844, 10321},  {8869, 19526},  {7789, 8973},   {3929, 14917},
      {19563, 20101}, {13931, 8138},  {8755, 7390},   {23413, 61},
      {1093, 11237},  {20975, 26283}, {13299, 20522}, {4507, 6468},
      {8475, 6585},   {8284, 21929},  {13648, 6074},  {9926, 15708},
      {29170, 2822},  {12980, 32437}, {18194, 18402}, {17061, 23578},
      {15311, 15243}, {2800, 26608},  {30984, 26119}, {10174, 20277},
      {16241, 32219}, {25311, 14208}, {3713, 13030},  {19553, 5980},
      {3429, 5690},   {12876, 13860}, {8128, 11485},  {1038, 21998},
      {22223, 2179},  {10037, 11322}, {11107, 29360}, {11112, 12016},
      {26215, 17820}, {7500, 20905},  {27068, 17295}, {16964, 10109},
      {12436, 8319},  {26586, 9974},  {15754, 20246}, {15793, 32145},
      {4195, 18450},  {3678, 7086},   {27842, 30348}, {5274, 8231},
      {23521, 21202}, {3372, 19249},  {25485, 26780}, {30035, 541},
      {4629, 26013},  {15878, 14394}, {16841, 13747}, {22322, 1804},
      {16275, 9113},  {10705, 30335}, {25428, 14186}, {28255, 27170},
      {24050, 288},   {6281, 17546},  {13824, 2296},  {17370, 3509},
      {13998, 12701}, {24868, 5261},  {4991, 3571},   {14611, 11364},
      {12648, 11053}, {19708, 14354}, {19618, 18735}, {15150, 8494},
      {27943, 23363}, {7164, 20756},  {5475, 13156},  {22529, 28376},
      {23213, 22008}, {810, 8492},    {26172, 32285}, {21245, 22748},
      {5957, 25233},  {7490, 23688},  {21918, 18027}, {11427, 17007},
      {29773, 1816},  {11378, 12428}, {21218, 29174}, {11340, 10327},
      {3812, 6415},   {10129, 11931}, {11891, 11731}, {20265, 6116},
      {16683, 14572}, {2192, 6621},   {7466, 13045},  {26984, 3337},
      {22661, 15528}, {30027, 31454}, {8400, 29418},  {18379, 15235},
      {21516, 31393}, {31350, 29417}, {21000, 5023},  {18218, 21075},
      {18580, 10125}, {16632, 2080},  {24917, 14972}, {12494, 12470},
      {24486, 4926},  {867, 30674},   {8711, 15090},  {23647, 15862},
      {14393, 31576}, {28014, 26680}, {8479, 5753},   {32060, 1520},
      {22086, 24930}, {439, 11114},   {31927, 26069}, {15691, 14275},
      {9186, 28407},  {19486, 15876}, {17722, 31748}, {29963, 13187},
      {20442, 7191},  {2590, 13247},  {8496, 10633},  {27830, 5493},
      {3567, 28198},  {30245, 11445}, {1871, 6289},   {20734, 29194},
      {21907, 8363},  {5723, 12548},  {6190, 15033},  {30958, 27424},
      {5421, 28446},  {10598, 28235}, {3377, 21666},  {9802, 17046},
      {19639, 14872}, {31624, 24542}, {1418, 12566},  {21464, 15978},
      {25681, 2831},  {20721, 24161}, {17616, 24821}, {7523, 26773},
      {23238, 17464}, {5821, 29592},  {3426, 31603},  {21282, 16299},
      {11097, 26107}, {24811, 8774},  {32046, 10633}, {9253, 21},
      {12750, 4996},  {18043, 21677}, {27116, 9302},  {16324, 24267}};

  for (const auto& [x, y] : P)
  {
    const auto expected = std::gcd(x, y);
    ASSERT_EQ(expected, gcd_bruteforce(x, y));
    ASSERT_EQ(expected, gcd_bruteforce(y, x));

    ASSERT_EQ(expected, gcd_euclide(x, y));
    ASSERT_EQ(expected, gcd_euclide(y, x));

    ASSERT_EQ(expected, gcd_euclide_iterative(x, y));
    ASSERT_EQ(expected, gcd_euclide_iterative(y, x));
  }
}

TEST(gcd, compiletimeprecpp11)
{
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<11375, 12161>::gcd;
    ASSERT_EQ(std::gcd(11375, 12161), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<12161, 11375>::gcd;
    ASSERT_EQ(std::gcd(11375, 12161), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<31303, 5783>::gcd;
    ASSERT_EQ(std::gcd(31303, 5783), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<5783, 31303>::gcd;
    ASSERT_EQ(std::gcd(31303, 5783), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<27927, 19868>::gcd;
    ASSERT_EQ(std::gcd(27927, 19868), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19868, 27927>::gcd;
    ASSERT_EQ(std::gcd(27927, 19868), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6918, 27117>::gcd;
    ASSERT_EQ(std::gcd(6918, 27117), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<27117, 6918>::gcd;
    ASSERT_EQ(std::gcd(6918, 27117), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4539, 31094>::gcd;
    ASSERT_EQ(std::gcd(4539, 31094), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<31094, 4539>::gcd;
    ASSERT_EQ(std::gcd(4539, 31094), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<15208, 21553>::gcd;
    ASSERT_EQ(std::gcd(15208, 21553), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<21553, 15208>::gcd;
    ASSERT_EQ(std::gcd(15208, 21553), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<22750, 11051>::gcd;
    ASSERT_EQ(std::gcd(22750, 11051), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<11051, 22750>::gcd;
    ASSERT_EQ(std::gcd(22750, 11051), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<30337, 31491>::gcd;
    ASSERT_EQ(std::gcd(30337, 31491), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<31491, 30337>::gcd;
    ASSERT_EQ(std::gcd(30337, 31491), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23713, 16188>::gcd;
    ASSERT_EQ(std::gcd(23713, 16188), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<16188, 23713>::gcd;
    ASSERT_EQ(std::gcd(23713, 16188), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<24198, 19638>::gcd;
    ASSERT_EQ(std::gcd(24198, 19638), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19638, 24198>::gcd;
    ASSERT_EQ(std::gcd(24198, 19638), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<31590, 23854>::gcd;
    ASSERT_EQ(std::gcd(31590, 23854), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23854, 31590>::gcd;
    ASSERT_EQ(std::gcd(31590, 23854), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<28861, 23200>::gcd;
    ASSERT_EQ(std::gcd(28861, 23200), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23200, 28861>::gcd;
    ASSERT_EQ(std::gcd(28861, 23200), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<2922, 29934>::gcd;
    ASSERT_EQ(std::gcd(2922, 29934), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<29934, 2922>::gcd;
    ASSERT_EQ(std::gcd(2922, 29934), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23091, 1466>::gcd;
    ASSERT_EQ(std::gcd(23091, 1466), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1466, 23091>::gcd;
    ASSERT_EQ(std::gcd(23091, 1466), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<24934, 19045>::gcd;
    ASSERT_EQ(std::gcd(24934, 19045), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19045, 24934>::gcd;
    ASSERT_EQ(std::gcd(24934, 19045), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<28730, 23085>::gcd;
    ASSERT_EQ(std::gcd(28730, 23085), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23085, 28730>::gcd;
    ASSERT_EQ(std::gcd(28730, 23085), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4651, 31589>::gcd;
    ASSERT_EQ(std::gcd(4651, 31589), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<31589, 4651>::gcd;
    ASSERT_EQ(std::gcd(4651, 31589), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<32216, 4665>::gcd;
    ASSERT_EQ(std::gcd(32216, 4665), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<4665, 32216>::gcd;
    ASSERT_EQ(std::gcd(32216, 4665), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1820, 10230>::gcd;
    ASSERT_EQ(std::gcd(1820, 10230), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10230, 1820>::gcd;
    ASSERT_EQ(std::gcd(1820, 10230), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<5950, 24211>::gcd;
    ASSERT_EQ(std::gcd(5950, 24211), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<24211, 5950>::gcd;
    ASSERT_EQ(std::gcd(5950, 24211), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<3591, 12176>::gcd;
    ASSERT_EQ(std::gcd(3591, 12176), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<12176, 3591>::gcd;
    ASSERT_EQ(std::gcd(3591, 12176), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6698, 30159>::gcd;
    ASSERT_EQ(std::gcd(6698, 30159), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<30159, 6698>::gcd;
    ASSERT_EQ(std::gcd(6698, 30159), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4815, 19782>::gcd;
    ASSERT_EQ(std::gcd(4815, 19782), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19782, 4815>::gcd;
    ASSERT_EQ(std::gcd(4815, 19782), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26214, 17927>::gcd;
    ASSERT_EQ(std::gcd(26214, 17927), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<17927, 26214>::gcd;
    ASSERT_EQ(std::gcd(26214, 17927), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6483, 10847>::gcd;
    ASSERT_EQ(std::gcd(6483, 10847), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10847, 6483>::gcd;
    ASSERT_EQ(std::gcd(6483, 10847), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23343, 1858>::gcd;
    ASSERT_EQ(std::gcd(23343, 1858), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1858, 23343>::gcd;
    ASSERT_EQ(std::gcd(23343, 1858), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6244, 24375>::gcd;
    ASSERT_EQ(std::gcd(6244, 24375), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<24375, 6244>::gcd;
    ASSERT_EQ(std::gcd(6244, 24375), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1075, 22982>::gcd;
    ASSERT_EQ(std::gcd(1075, 22982), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<22982, 1075>::gcd;
    ASSERT_EQ(std::gcd(1075, 22982), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<29051, 8823>::gcd;
    ASSERT_EQ(std::gcd(29051, 8823), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<8823, 29051>::gcd;
    ASSERT_EQ(std::gcd(29051, 8823), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<22259, 10584>::gcd;
    ASSERT_EQ(std::gcd(22259, 10584), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10584, 22259>::gcd;
    ASSERT_EQ(std::gcd(22259, 10584), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<32467, 19682>::gcd;
    ASSERT_EQ(std::gcd(32467, 19682), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19682, 32467>::gcd;
    ASSERT_EQ(std::gcd(32467, 19682), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<21629, 972>::gcd;
    ASSERT_EQ(std::gcd(21629, 972), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<972, 21629>::gcd;
    ASSERT_EQ(std::gcd(21629, 972), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1042, 149>::gcd;
    ASSERT_EQ(std::gcd(1042, 149), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<149, 1042>::gcd;
    ASSERT_EQ(std::gcd(1042, 149), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<10057, 1607>::gcd;
    ASSERT_EQ(std::gcd(10057, 1607), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1607, 10057>::gcd;
    ASSERT_EQ(std::gcd(10057, 1607), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<139, 7163>::gcd;
    ASSERT_EQ(std::gcd(139, 7163), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<7163, 139>::gcd;
    ASSERT_EQ(std::gcd(139, 7163), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<5754, 3294>::gcd;
    ASSERT_EQ(std::gcd(5754, 3294), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<3294, 5754>::gcd;
    ASSERT_EQ(std::gcd(5754, 3294), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26000, 15968>::gcd;
    ASSERT_EQ(std::gcd(26000, 15968), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<15968, 26000>::gcd;
    ASSERT_EQ(std::gcd(26000, 15968), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<16291, 16680>::gcd;
    ASSERT_EQ(std::gcd(16291, 16680), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<16680, 16291>::gcd;
    ASSERT_EQ(std::gcd(16291, 16680), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<24674, 3174>::gcd;
    ASSERT_EQ(std::gcd(24674, 3174), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<3174, 24674>::gcd;
    ASSERT_EQ(std::gcd(24674, 3174), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26163, 19794>::gcd;
    ASSERT_EQ(std::gcd(26163, 19794), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<19794, 26163>::gcd;
    ASSERT_EQ(std::gcd(26163, 19794), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<19864, 5735>::gcd;
    ASSERT_EQ(std::gcd(19864, 5735), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<5735, 19864>::gcd;
    ASSERT_EQ(std::gcd(19864, 5735), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6347, 32057>::gcd;
    ASSERT_EQ(std::gcd(6347, 32057), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<32057, 6347>::gcd;
    ASSERT_EQ(std::gcd(6347, 32057), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<31424, 7591>::gcd;
    ASSERT_EQ(std::gcd(31424, 7591), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<7591, 31424>::gcd;
    ASSERT_EQ(std::gcd(31424, 7591), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1631, 21134>::gcd;
    ASSERT_EQ(std::gcd(1631, 21134), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<21134, 1631>::gcd;
    ASSERT_EQ(std::gcd(1631, 21134), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23709, 12575>::gcd;
    ASSERT_EQ(std::gcd(23709, 12575), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<12575, 23709>::gcd;
    ASSERT_EQ(std::gcd(23709, 12575), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<28036, 11052>::gcd;
    ASSERT_EQ(std::gcd(28036, 11052), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<11052, 28036>::gcd;
    ASSERT_EQ(std::gcd(28036, 11052), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<18196, 22802>::gcd;
    ASSERT_EQ(std::gcd(18196, 22802), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<22802, 18196>::gcd;
    ASSERT_EQ(std::gcd(18196, 22802), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<974, 1608>::gcd;
    ASSERT_EQ(std::gcd(974, 1608), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1608, 974>::gcd;
    ASSERT_EQ(std::gcd(974, 1608), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<18901, 23072>::gcd;
    ASSERT_EQ(std::gcd(18901, 23072), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23072, 18901>::gcd;
    ASSERT_EQ(std::gcd(18901, 23072), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<31706, 30119>::gcd;
    ASSERT_EQ(std::gcd(31706, 30119), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<30119, 31706>::gcd;
    ASSERT_EQ(std::gcd(31706, 30119), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<5286, 15825>::gcd;
    ASSERT_EQ(std::gcd(5286, 15825), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<15825, 5286>::gcd;
    ASSERT_EQ(std::gcd(5286, 15825), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<13826, 6790>::gcd;
    ASSERT_EQ(std::gcd(13826, 6790), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<6790, 13826>::gcd;
    ASSERT_EQ(std::gcd(13826, 6790), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<10390, 11275>::gcd;
    ASSERT_EQ(std::gcd(10390, 11275), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<11275, 10390>::gcd;
    ASSERT_EQ(std::gcd(10390, 11275), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6901, 1697>::gcd;
    ASSERT_EQ(std::gcd(6901, 1697), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1697, 6901>::gcd;
    ASSERT_EQ(std::gcd(6901, 1697), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1454, 6683>::gcd;
    ASSERT_EQ(std::gcd(1454, 6683), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<6683, 1454>::gcd;
    ASSERT_EQ(std::gcd(1454, 6683), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<21634, 25566>::gcd;
    ASSERT_EQ(std::gcd(21634, 25566), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<25566, 21634>::gcd;
    ASSERT_EQ(std::gcd(21634, 25566), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<32398, 14852>::gcd;
    ASSERT_EQ(std::gcd(32398, 14852), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<14852, 32398>::gcd;
    ASSERT_EQ(std::gcd(32398, 14852), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<20454, 26974>::gcd;
    ASSERT_EQ(std::gcd(20454, 26974), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<26974, 20454>::gcd;
    ASSERT_EQ(std::gcd(20454, 26974), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4345, 13774>::gcd;
    ASSERT_EQ(std::gcd(4345, 13774), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<13774, 4345>::gcd;
    ASSERT_EQ(std::gcd(4345, 13774), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<28202, 20783>::gcd;
    ASSERT_EQ(std::gcd(28202, 20783), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<20783, 28202>::gcd;
    ASSERT_EQ(std::gcd(28202, 20783), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<9758, 31408>::gcd;
    ASSERT_EQ(std::gcd(9758, 31408), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<31408, 9758>::gcd;
    ASSERT_EQ(std::gcd(9758, 31408), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<8679, 9239>::gcd;
    ASSERT_EQ(std::gcd(8679, 9239), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<9239, 8679>::gcd;
    ASSERT_EQ(std::gcd(8679, 9239), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<8246, 29107>::gcd;
    ASSERT_EQ(std::gcd(8246, 29107), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<29107, 8246>::gcd;
    ASSERT_EQ(std::gcd(8246, 29107), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<18380, 24319>::gcd;
    ASSERT_EQ(std::gcd(18380, 24319), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<24319, 18380>::gcd;
    ASSERT_EQ(std::gcd(18380, 24319), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<160, 32255>::gcd;
    ASSERT_EQ(std::gcd(160, 32255), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<32255, 160>::gcd;
    ASSERT_EQ(std::gcd(160, 32255), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<3204, 7154>::gcd;
    ASSERT_EQ(std::gcd(3204, 7154), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<7154, 3204>::gcd;
    ASSERT_EQ(std::gcd(3204, 7154), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1558, 10946>::gcd;
    ASSERT_EQ(std::gcd(1558, 10946), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10946, 1558>::gcd;
    ASSERT_EQ(std::gcd(1558, 10946), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<11221, 604>::gcd;
    ASSERT_EQ(std::gcd(11221, 604), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<604, 11221>::gcd;
    ASSERT_EQ(std::gcd(11221, 604), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<12487, 1059>::gcd;
    ASSERT_EQ(std::gcd(12487, 1059), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<1059, 12487>::gcd;
    ASSERT_EQ(std::gcd(12487, 1059), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<27342, 23929>::gcd;
    ASSERT_EQ(std::gcd(27342, 23929), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23929, 27342>::gcd;
    ASSERT_EQ(std::gcd(27342, 23929), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<7645, 30404>::gcd;
    ASSERT_EQ(std::gcd(7645, 30404), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<30404, 7645>::gcd;
    ASSERT_EQ(std::gcd(7645, 30404), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<9685, 27729>::gcd;
    ASSERT_EQ(std::gcd(9685, 27729), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<27729, 9685>::gcd;
    ASSERT_EQ(std::gcd(9685, 27729), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23095, 9155>::gcd;
    ASSERT_EQ(std::gcd(23095, 9155), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<9155, 23095>::gcd;
    ASSERT_EQ(std::gcd(23095, 9155), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<17333, 25406>::gcd;
    ASSERT_EQ(std::gcd(17333, 25406), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<25406, 17333>::gcd;
    ASSERT_EQ(std::gcd(17333, 25406), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<20561, 9024>::gcd;
    ASSERT_EQ(std::gcd(20561, 9024), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<9024, 20561>::gcd;
    ASSERT_EQ(std::gcd(20561, 9024), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<9061, 29963>::gcd;
    ASSERT_EQ(std::gcd(9061, 29963), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<29963, 9061>::gcd;
    ASSERT_EQ(std::gcd(9061, 29963), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4386, 21387>::gcd;
    ASSERT_EQ(std::gcd(4386, 21387), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<21387, 4386>::gcd;
    ASSERT_EQ(std::gcd(4386, 21387), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26664, 18723>::gcd;
    ASSERT_EQ(std::gcd(26664, 18723), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<18723, 26664>::gcd;
    ASSERT_EQ(std::gcd(26664, 18723), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26237, 26719>::gcd;
    ASSERT_EQ(std::gcd(26237, 26719), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<26719, 26237>::gcd;
    ASSERT_EQ(std::gcd(26237, 26719), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<19728, 3497>::gcd;
    ASSERT_EQ(std::gcd(19728, 3497), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<3497, 19728>::gcd;
    ASSERT_EQ(std::gcd(19728, 3497), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4809, 10506>::gcd;
    ASSERT_EQ(std::gcd(4809, 10506), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10506, 4809>::gcd;
    ASSERT_EQ(std::gcd(4809, 10506), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<4499, 12427>::gcd;
    ASSERT_EQ(std::gcd(4499, 12427), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<12427, 4499>::gcd;
    ASSERT_EQ(std::gcd(4499, 12427), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<9435, 10977>::gcd;
    ASSERT_EQ(std::gcd(9435, 10977), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<10977, 9435>::gcd;
    ASSERT_EQ(std::gcd(9435, 10977), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<8162, 23199>::gcd;
    ASSERT_EQ(std::gcd(8162, 23199), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23199, 8162>::gcd;
    ASSERT_EQ(std::gcd(8162, 23199), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<23488, 28157>::gcd;
    ASSERT_EQ(std::gcd(23488, 28157), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<28157, 23488>::gcd;
    ASSERT_EQ(std::gcd(23488, 28157), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<20007, 24230>::gcd;
    ASSERT_EQ(std::gcd(20007, 24230), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<24230, 20007>::gcd;
    ASSERT_EQ(std::gcd(20007, 24230), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<28269, 20224>::gcd;
    ASSERT_EQ(std::gcd(28269, 20224), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<20224, 28269>::gcd;
    ASSERT_EQ(std::gcd(28269, 20224), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<6801, 23145>::gcd;
    ASSERT_EQ(std::gcd(6801, 23145), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23145, 6801>::gcd;
    ASSERT_EQ(std::gcd(6801, 23145), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<12002, 3753>::gcd;
    ASSERT_EQ(std::gcd(12002, 3753), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<3753, 12002>::gcd;
    ASSERT_EQ(std::gcd(12002, 3753), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<1942, 5484>::gcd;
    ASSERT_EQ(std::gcd(1942, 5484), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<5484, 1942>::gcd;
    ASSERT_EQ(std::gcd(1942, 5484), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<2757, 5962>::gcd;
    ASSERT_EQ(std::gcd(2757, 5962), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<5962, 2757>::gcd;
    ASSERT_EQ(std::gcd(2757, 5962), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<21732, 12609>::gcd;
    ASSERT_EQ(std::gcd(21732, 12609), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<12609, 21732>::gcd;
    ASSERT_EQ(std::gcd(21732, 12609), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<8034, 14995>::gcd;
    ASSERT_EQ(std::gcd(8034, 14995), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<14995, 8034>::gcd;
    ASSERT_EQ(std::gcd(8034, 14995), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<18342, 11223>::gcd;
    ASSERT_EQ(std::gcd(18342, 11223), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<11223, 18342>::gcd;
    ASSERT_EQ(std::gcd(18342, 11223), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<7255, 9392>::gcd;
    ASSERT_EQ(std::gcd(7255, 9392), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<9392, 7255>::gcd;
    ASSERT_EQ(std::gcd(7255, 9392), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<14121, 4405>::gcd;
    ASSERT_EQ(std::gcd(14121, 4405), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<4405, 14121>::gcd;
    ASSERT_EQ(std::gcd(14121, 4405), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<25030, 23295>::gcd;
    ASSERT_EQ(std::gcd(25030, 23295), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<23295, 25030>::gcd;
    ASSERT_EQ(std::gcd(25030, 23295), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<2909, 13527>::gcd;
    ASSERT_EQ(std::gcd(2909, 13527), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<13527, 2909>::gcd;
    ASSERT_EQ(std::gcd(2909, 13527), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<26578, 15344>::gcd;
    ASSERT_EQ(std::gcd(26578, 15344), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<15344, 26578>::gcd;
    ASSERT_EQ(std::gcd(26578, 15344), cpp11ans2);
  }
  {
    constexpr auto cpp11ans1 = GCDEuclidePreCpp11<29451, 14018>::gcd;
    ASSERT_EQ(std::gcd(29451, 14018), cpp11ans1);
    constexpr auto cpp11ans2 = GCDEuclidePreCpp11<14018, 29451>::gcd;
    ASSERT_EQ(std::gcd(29451, 14018), cpp11ans2);
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
