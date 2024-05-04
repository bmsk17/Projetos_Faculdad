import unittest
from selenium.webdriver import Firefox
from pages.login_page import LoginPage
import time


class ProcedimentoTesteLogin(unittest.TestCase):

    def setUp(self):
        self.driver = Firefox()
        self.login_page = LoginPage(self.driver)
        

    def test_valid_login(self):
        self.login_page.fill_credentials('coloca tua conta aqui', 'coloca tua senha aqui')
        self.login_page.perform_login()

        time.sleep(3)
        
        self.assertEqual(self.driver.current_url, 'https://www.kabum.com.br/')

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    unittest.main()
