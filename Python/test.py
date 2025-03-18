from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import pandas as pd

# Configure WebDriver
options = webdriver.ChromeOptions()
options.add_argument("--headless")  # Run in headless mode
driver = webdriver.Chrome(options=options)

# Target Job Site (Update URL based on your choice)
job_site_url = "https://www.naukri.com/devops-jobs-in-bangalore"
driver.get(job_site_url)

try:
    # Wait for job postings to load
    job_cards = WebDriverWait(driver, 10).until(
        EC.presence_of_all_elements_located((By.CSS_SELECTOR, '[class*="jobTuple"]'))  # Dynamic class detection
    )
except:
    print("No job postings found! Check the website structure.")
    driver.quit()
    exit()

# Extract job details
job_list = []
for job in job_cards:
    try:
        title = job.find_element(By.CSS_SELECTOR, '[class*="title"]').text
        company = job.find_element(By.CSS_SELECTOR, '[class*="company"]').text
        link = job.find_element(By.TAG_NAME, "a").get_attribute("href")
        job_list.append({"Title": title, "Company": company, "Link": link})
    except Exception as e:
        print("Error extracting job:", e)

# Save results
df = pd.DataFrame(job_list)
df.to_csv("devops_jobs.csv", index=False)
print(f"Found {len(job_list)} jobs. Saved to devops_jobs.csv.")

# Close browser
driver.quit()
