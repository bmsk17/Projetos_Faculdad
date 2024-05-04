
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By


class BasePage():
    """The BasePage class holds all common functionality across the website.
    Also provides a nice wrapper when dealing with selenium functions that may
    not be easy to understand.
    """

    def __init__(self, driver):
        """ This function is called every time a new object of the base class is created"""
        self.driver = driver
    
    def find_element(self, locator):
        return self.driver.find_element(*locator)
      
    def click(self, by_locator):
        """ Performs click on web element whose locator is passed to it"""
        WebDriverWait(self.driver, 10).until(
            EC.visibility_of_element_located(by_locator)).click()

    def enter_text(self, by_locator, text):
        """ Performs text entry of the passed in text, in a web element whose locator is passed to it"""
        return WebDriverWait(self.driver, 10).until(EC.visibility_of_element_located(by_locator)).send_keys(text)

    def get_title(self) -> str:
        """Returns the title of the page"""
        return self.driver.title

    def get_url(self) -> str:
        return self.driver.current_url
