from selenium.webdriver.common.by import By


class LoginLocators():
    field_login = (By.ID, 'login')
    field_password = (By.ID, 'password')
    button_login = (By.CLASS_NAME, 'IconLoginButton')

class SearchLocators():
    field_search = (By.NAME, 'query')

class SaqPageLocators:
    SAQ_LINK = (By.CSS_SELECTOR, 'a[href="/faq"]')

class FAQFilterPageLocators:
    CODIGO_CONDUTA_LINK = (By.LINK_TEXT, "Código de Conduta e Ética")