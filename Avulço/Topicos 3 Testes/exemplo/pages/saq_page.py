from pages.base_page import BasePage
from locators.locators import SaqPageLocators
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time



class SACPage(BasePage):
    def __init__(self, driver):
        super().__init__(driver)
        self.driver.get('https://www.kabum.com.br/')

    def click_sac_link(self):
        element = WebDriverWait(self.driver, 10).until(
            EC.element_to_be_clickable(SaqPageLocators.SAQ_LINK))
        element.click()
        time.sleep(2)
        element.click()