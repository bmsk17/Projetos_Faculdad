import unittest
from selenium.webdriver import Firefox
from pages.saq_page import SACPage
import time

class TestSACPage(unittest.TestCase):

    def setUp(self):
        self.driver = Firefox()
        self.saq_page = SACPage(self.driver)

    def test_click_sac_link(self):
        self.saq_page.click_sac_link()
        time.sleep(10)
        self.assertEqual(self.driver.current_url, 'https://www.kabum.com.br/faq')

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    unittest.main()