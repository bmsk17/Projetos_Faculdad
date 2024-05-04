from pages.base_page import BasePage
from locators.locators import LoginLocators


class LoginPage(BasePage):

    def __init__(self, driver):
        super().__init__(driver)
        driver.get('https://www.kabum.com.br/login')

    def fill_credentials(self, login, password):
        self.enter_text(LoginLocators.field_login, login)
        self.enter_text(LoginLocators.field_password, password)

    def perform_login(self):
        self.click(LoginLocators.button_login)

