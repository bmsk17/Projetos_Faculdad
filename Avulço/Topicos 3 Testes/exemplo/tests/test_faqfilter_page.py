import unittest
from selenium.webdriver import Firefox
from pages.faqfilter_page import FAQFilterPage

class TestFAQFilterPage(unittest.TestCase):

    def setUp(self):
        self.driver = Firefox()
        self.faqfilter_page = FAQFilterPage(self.driver)

    def test_click_codigo_conduta_link(self):
        self.faqfilter_page.click_codigo_conduta_link()
        self.assertEqual(self.driver.current_url, 'https://www.kabum.com.br/codigo-conduta')

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    unittest.main()