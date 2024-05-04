from pages.base_page import BasePage
from locators.locators import AccessibilityPageLocators

class AccessibilityPage(BasePage):

    def __init__(self, driver):
        super().__init__(driver)
        self.driver.get('https://www.kabum.com.br/')

    def clicar_botao_abrir_acessibilidade(self):
        botao_abrir_acessibilidade = self.driver.find_element(
            AccessibilityPageLocators.BOTAO_ABRIR_ACESSIBILIDADE)
        botao_abrir_acessibilidade.click()
        
        botao_acessibilidade = self.driver.find_element(
            AccessibilityPageLocators.BOTAO_ACESSIBILIDADE)
        botao_acessibilidade.click()