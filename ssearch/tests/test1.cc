#include <gtest/gtest.h>

#include "../ssearch.h"

class SimpleSubStrTest : public ::testing::Test {
protected:
    void SetUp() override {
        stringSearch = new StringSearch();
    }

    void TearDown() override {
        delete stringSearch;
    }

    StringSearch* stringSearch;
};

class ZFunc1Test : public SimpleSubStrTest {
};

TEST_F(SimpleSubStrTest, EmptyStrings) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("", "");
    EXPECT_TRUE(result.empty());
}

TEST_F(SimpleSubStrTest, EmptyPattern) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abc", "");
    EXPECT_TRUE(result.empty());
}

TEST_F(SimpleSubStrTest, EmptyString) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("", "pattern");
    EXPECT_TRUE(result.empty());
}

TEST_F(SimpleSubStrTest, NoMatches) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abcdefgh", "xyz");
    EXPECT_TRUE(result.empty());
}

TEST_F(SimpleSubStrTest, SingleMatch) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abcacabc", "bca");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].first, 1);
    EXPECT_EQ(result[0].second, 3);

    auto res2 = stringSearch->SimpleSubStr("abcacabc", "bca");

    EXPECT_EQ(res2, result);
}

TEST_F(SimpleSubStrTest, DoubleMatch) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abcabcabc", "bca");
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].first, 1);
    EXPECT_EQ(result[0].second, 3);

    EXPECT_EQ(result[1].first, 4);
    EXPECT_EQ(result[1].second, 6);

    auto res2 = stringSearch->SimpleSubStr("abcabcabc", "bca");

    EXPECT_EQ(res2, result);
}

TEST_F(SimpleSubStrTest, MultipleMatches) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abababab", "ab");
    EXPECT_EQ(result.size(), 4);

    EXPECT_EQ(result[0].first, 0);
    EXPECT_EQ(result[0].second, 1);

    EXPECT_EQ(result[1].first, 2);
    EXPECT_EQ(result[1].second, 3);

    EXPECT_EQ(result[2].first, 4);
    EXPECT_EQ(result[2].second, 5);

    EXPECT_EQ(result[3].first, 6);
    EXPECT_EQ(result[3].second, 7);

    auto res2 = stringSearch->ZSubStr("abababab", "ab");

    EXPECT_EQ(res2, result);
}

TEST_F(SimpleSubStrTest, PatternLongerThanString) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abc", "abcdef");
    EXPECT_TRUE(result.empty());
}

TEST_F(SimpleSubStrTest, PatternEqualsString) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("abc", "abc");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].first, 0);
    EXPECT_EQ(result[0].second, 2);
}

TEST_F(SimpleSubStrTest, CaseSensitive) {
    std::vector<StringSearch::ipair> result = stringSearch->SimpleSubStr("AbC", "abc");
    EXPECT_TRUE(result.empty());
}

/* TEST_F(ZFunc1Test, EmptyString) { */
/*     std::vector<int> result = stringSearch->ZFunc1(""); */
/*     EXPECT_TRUE(result.empty()); */
/* } */

TEST_F(ZFunc1Test, SingleCharacterString) {
    std::vector<int> result2 = stringSearch->ZFunc1("a");

    EXPECT_EQ(result2.size(), 1);
    EXPECT_EQ(result2[0], 0);
}

TEST_F(ZFunc1Test, NoRepeatedPrefixes) {
    std::vector<int> result = stringSearch->ZFunc1("abcde");
    EXPECT_EQ(result.size(), 5);
    for (int value : result) {
        EXPECT_EQ(value, 0);
    }
}

TEST_F(ZFunc1Test, SimpleRepeatedPrefixes) {
    std::vector<int> expected{0, 0, 4, 0, 2, 0};
    std::vector<int> result = stringSearch->ZFunc1("ababab");
    EXPECT_EQ(result, expected);
}

TEST_F(ZFunc1Test, ComplexRepeatedPrefixes) {
    std::vector<int> expected{0, 0, 1, 0, 3, 0, 1, 0, 7, 0, 1, 0, 3, 0, 1};
    std::vector<int> result = stringSearch->ZFunc1("abacabadabacaba");
    EXPECT_EQ(result, expected);
}

TEST_F(ZFunc1Test, RandomTestCase1) {
    std::vector<int> expected{0, 0, 1, 0, 3, 0, 1};
    std::vector<int> result = stringSearch->ZFunc1("abacaba");
    EXPECT_EQ(result, expected);
}

TEST_F(ZFunc1Test, RandomTestCase2) {
    std::vector<int> expected{0, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> result = stringSearch->ZFunc1("aaaaaaaa");
    EXPECT_EQ(result, expected);
}

TEST_F(ZFunc1Test, RandomTestCase3) {
    std::vector<int> expected{0, 0, 6, 0, 4, 0, 2, 0};
    std::vector<int> result = stringSearch->ZFunc1("abababab");
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
