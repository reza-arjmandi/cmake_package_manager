
TEST(test_suite, test_case1)
{
    ASSERT_TRUE(true);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}