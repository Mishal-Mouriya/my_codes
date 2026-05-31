#we are learning how to run test on a function
#read python edition 3 i will give only basics here
#=======================================================================
''' 1. File and functions name must start with test_ or else pytest won't detect them.

    2. You can run the test using this command in the terminal:
    py -m pytest "path"
'''
#========================================================================

import pytest
from importable_folder_magic import formatted_name, Anonymous_survey

# ------------------------------
# ✅ FUNCTION TESTING
# ------------------------------

def test_formatted_func():
    '''Test whether the function accepts middle names.'''
    assert formatted_name("John", "gopal", "Smith") == "John gopal Smith"

def test_formatted_func2():
    '''Test whether the function accepts integers as input.'''
    assert formatted_name("John", "123") == "John 123"

# ------------------------------
# ✅ CLASS TEST WITHOUT FIXTURE
# ------------------------------

def test_multi_responses():
    '''Test storing multiple responses without fixture.'''
    question = "What is your language?"
    language_survey = Anonymous_survey(question)
    language_survey.store_responses("english", "tamil")
    assert len(language_survey.responses) == 2
    assert "english" in language_survey.responses
    assert "tamil" in language_survey.responses

# ------------------------------
# 🌟 FIXTURE-BASED TESTING (EXPLAINED)
# ------------------------------

@pytest.fixture
def sample_survey():
    '''
    This fixture creates and returns an Anonymous_survey instance.
    - It avoids repeating setup code in every test function.
    '''
    question = "What is your language?"
    return Anonymous_survey(question)

def test_store_two_languages(sample_survey):
    '''Test storing responses using the shared fixture object.'''
    sample_survey.store_responses("English", "Tamil")
    assert "English" in sample_survey.responses
    assert "Tamil" in sample_survey.responses
    assert len(sample_survey.responses) == 2

# 📘 Fixture Recap:
# - Decorator @pytest.fixture marks a function as a reusable setup helper
# - Any test with a matching parameter name (like sample_survey) receives it automatically
# - Great for avoiding copy-paste setup code in large projects
# - Makes tests cleaner, more readable, and easier to maintain
