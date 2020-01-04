#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "string_reverse_solution1.cpp"
#include "string_reverse_solution2.cpp"
#include "string_reverse_solution3.cpp"
#include "string_reverse_solution4.cpp"



TEST(string_reverse, test_empty)
{
	std::string s ="";
	const std::string expected(s);
	EXPECT_EQ(expected,reverse_string_outplace_raw_loop(s));
	EXPECT_EQ(expected,reverse_string_outplace_iterator(s));
	{	
		std::string scopy(s);
		reverse_string_inplace(scopy);
		EXPECT_EQ(expected,scopy);
	}
	{	
		std::string scopy(s);
		reverse_string_inplace_recursive(scopy);
		EXPECT_EQ(expected,scopy);
	}
}

TEST(string_reverse, test_single)
{
	std::string s ="a";
	const std::string expected(s);
	EXPECT_EQ(expected,reverse_string_outplace_raw_loop(s));
	EXPECT_EQ(expected,reverse_string_outplace_iterator(s));
	{	
		std::string scopy(s);
		reverse_string_inplace(scopy);
		EXPECT_EQ(expected,scopy);
	}
}

TEST(string_reverse, test_abcde)
{
	std::string s ="abcde";
	const std::string expected="edcba";
	EXPECT_EQ(expected,reverse_string_outplace_raw_loop(s));
	EXPECT_EQ(expected,reverse_string_outplace_iterator(s));
	{	
		std::string scopy(s);
		reverse_string_inplace(scopy);
		EXPECT_EQ(expected,scopy);
	}
}

TEST(string_reverse, test_dante_inferno)
{
	std::string s =R"(Midway upon the journey of our life
  I found myself within a forest dark,
  For the straightforward pathway had been lost.

Ah me! how hard a thing it is to say
  What was this forest savage, rough, and stern,
  Which in the very thought renews the fear.

So bitter is it, death is little more;
  But of the good to treat, which there I found,
  Speak will I of the other things I saw there.

I cannot well repeat how there I entered,
  So full was I of slumber at the moment
  In which I had abandoned the true way.

But after I had reached a mountain's foot,
  At that point where the valley terminated,
  Which had with consternation pierced my heart,

Upward I looked, and I beheld its shoulders,
  Vested already with that planet's rays
  Which leadeth others right by every road.)";

	const std::string expected=R"(.daor yreve yb thgir srehto htedael hcihW  
syar s'tenalp taht htiw ydaerla detseV  
,sredluohs sti dleheb I dna ,dekool I drawpU

,traeh ym decreip noitanretsnoc htiw dah hcihW  
,detanimret yellav eht erehw tniop taht tA  
,toof s'niatnuom a dehcaer dah I retfa tuB

.yaw eurt eht denodnaba dah I hcihw nI  
tnemom eht ta rebmuls fo I saw lluf oS  
,deretne I ereht woh taeper llew tonnac I

.ereht was I sgniht rehto eht fo I lliw kaepS  
,dnuof I ereht hcihw ,taert ot doog eht fo tuB  
;erom elttil si htaed ,ti si rettib oS

.raef eht swener thguoht yrev eht ni hcihW  
,nrets dna ,hguor ,egavas tserof siht saw tahW  
yas ot si ti gniht a drah woh !em hA

.tsol neeb dah yawhtap drawrofthgiarts eht roF  
,krad tserof a nihtiw flesym dnuof I  
efil ruo fo yenruoj eht nopu yawdiM)";


	EXPECT_EQ(expected,reverse_string_outplace_raw_loop(s));
	EXPECT_EQ(expected,reverse_string_outplace_iterator(s));
	{	
		std::string scopy(s);
		reverse_string_inplace(scopy);
		EXPECT_EQ(expected,scopy);
	}
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

