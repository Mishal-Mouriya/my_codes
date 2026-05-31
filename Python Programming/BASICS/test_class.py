import pytest

# ------------------------------
# 🧩 CLASS DEFINITION
# ------------------------------
class Anonymous_survey:
    def __init__(self, question):
        self.question = question
        self.responses = []

    def show_question(self):
        print(self.question)

    def store_responses(self, *args):
        for x in args:
            self.responses.append(x)

    def show_responses(self):
        for x in self.responses:
            print(f" -{x}")

# ------------------------------
# ✅ FUNCTIONAL TEST WITHOUT FIXTURE
# ------------------------------
from importable_folder_magic import Anonymous_survey

def test_multi_respones():
    question = "What is your language?"
    language_survey = Anonymous_survey(question)
    language_survey.store_responses("english", "tamil")
    assert len(language_survey.responses) == 2

# ------------------------------
# 🌟 FIXTURE-BASED TESTING (EXPLAINED)
# ------------------------------

# ✅ Fixture to avoid repeating object creation in every test
@pytest.fixture
def sample_survey():
    """
    This fixture creates and returns an Anonymous_survey instance.
    - The function is marked with @pytest.fixture
    - Pytest automatically calls this before test functions that have a 'sample_survey' parameter
    - This avoids rewriting the setup code in every test function
    """
    question = "What is your language?"
    return Anonymous_survey(question)

# ✅ Example test using the fixture

def test_store_two_languages(sample_survey):
    sample_survey.store_responses("English", "Tamil")
    assert "English" in sample_survey.responses
    assert "Tamil" in sample_survey.responses
    assert len(sample_survey.responses) == 2

# 📘 Fixture Recap:
# - Decorator @pytest.fixture marks a function as a reusable setup helper
# - Any test with a matching parameter name (like sample_survey) receives it automatically
# - Great for avoiding copy-paste setup code in large projects
# - Makes tests cleaner, more readable, and easier to maintain
