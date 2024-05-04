import unittest
from selenium.webdriver import Firefox
from pages.search_page import Search
import time

class ProcedimentoTesteBusca(unittest.TestCase):

    def setUp(self):
        self.driver = Firefox()
        self.search_page = Search(self.driver)

    def test_search(self):
        self.search_page.search_product('Placa de Vídeo')  
        time.sleep(3)
        self.assertEqual(self.driver.current_url, 'https://www.kabum.com.br/hardware/placa-de-video-vga')

    def tearDown(self):
        self.driver.quit()

if __name__ == "__main__":
    unittest.main()
