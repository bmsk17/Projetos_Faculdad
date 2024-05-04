from pages.base_page import BasePage
from locators.locators import SearchLocators
from selenium.webdriver.common.keys import Keys


class Search(BasePage):
    def __init__(self, driver):
        super().__init__(driver)
        self.driver.get('https://www.kabum.com.br/')

    def search_product(self, search_string):
        search_input = self.find_element(SearchLocators.field_search)
        search_input.send_keys(search_string)
        search_input.send_keys(Keys.ENTER)
        
        
