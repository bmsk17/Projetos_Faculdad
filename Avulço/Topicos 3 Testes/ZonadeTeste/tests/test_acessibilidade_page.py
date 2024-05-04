import unittest
from selenium.webdriver import Firefox
from pages.acessibilidade_page import AccessibilityPage
import time

class TestAccessibilityPage(unittest.TestCase):

    def setUp(self):
        self.driver = Firefox()
        self.acessibilidade_page = AccessibilityPage(self.driver)

    def test_clicar_botao_acessibilidade(self):
        self.acessibilidade_page.clicar_botao_abrir_acessibilidade()
        time.sleep(3)
        self.assertEqual(self.driver.current_url, 'https://www.kabum.com.br/acessibilidade')

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    unittest.main()