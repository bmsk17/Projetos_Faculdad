from pages.base_page import BasePage
from locators.locators import FAQFilterPageLocators
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time



class FAQFilterPage(BasePage):
    def __init__(self, driver):
        super().__init__(driver)
        self.driver.get('https://www.kabum.com.br/faq')

    def click_codigo_conduta_link(self):
        wait = WebDriverWait(self.driver, 10)
        elemento = wait.until(
            EC.visibility_of_element_located(FAQFilterPageLocators.CODIGO_CONDUTA_LINK))
        self.driver.execute_script("arguments[0].scrollIntoView();", elemento)
        elemento.click()