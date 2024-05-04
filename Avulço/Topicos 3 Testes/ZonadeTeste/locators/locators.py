from selenium.webdriver.common.by import By

class SaqPageLocators:
    SAQ_LINK = (By.CSS_SELECTOR, 'a[href="/faq"]')

class SearchLocators():
    field_search = (By.NAME, 'query')

class FAQFilterPageLocators:
    CODIGO_CONDUTA_LINK = (By.LINK_TEXT, "Código de Conduta e Ética")

class AccessibilityPageLocators:
    BOTAO_ABRIR_ACESSIBILIDADE = (By.CSS_SELECTOR, 'button[aria-label="Abrir opções de acessibilidade"]')
    BOTAO_ACESSIBILIDADE = (By.CSS_SELECTOR, 'a[href="/acessibilidade"]')